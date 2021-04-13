#include "MyFileIo.h"

typedef double (*funcPtr)(double _tvar);

funcPtr charToFunc(char _single_char){
    funcPtr retvar;
    switch (_single_char)
    {
    case 'u':
        retvar = unit;
        break;
    
    case 'i':
        retvar = impulse;
        break;
    
    case 's':
        retvar = sin;
        break;
    case 'r':
        retvar = ramp;
        break;
    
    default:
        retvar = unit;
        break;
    }
    return retvar;
}

void fileToFOLODEnSolObj(char *_path_to_data, FirstOrderLinearODE* _FOLODE_Obj, OdeSolverObject* _solObj){
    FILE *fp = fopen(_path_to_data, "r");
    double _fA = 0.0;
    double _fB = 0.0;
    char _f_ip = ' ';
    double _fts = 0.0;
    double _finitState = 0.0;
    double _ffreq = 1;
    double _ft0 = 0.0, _ftend = 0.0, _fdt = 0.0;
    
    fscanf(fp, "%lf\n%lf\n%c %lf %lf\n%lf\n%lf %lf %lf",
     &_fA,
     &_fB,
     &_f_ip, &_fts, &_ffreq,
     &_finitState,
     &_ft0, &_ftend, &_fdt
    );
    
    FOLODE_init(_FOLODE_Obj, _fA, _fB, charToFunc(_f_ip), _fts, _finitState, _ffreq);
    solverInit(_solObj, _ft0, _ftend, _fdt, _finitState);
    
    fclose(fp);
}

void saveSolToCsv(OdeSolverObject* _solObj){
    FILE *solcsv;
    solcsv = fopen("soln.csv", "w");
    for(int i = 0; i < _solObj->Npoints; i++)
        fprintf(solcsv, "%lf,%lf\n", _solObj->timeArr[i], _solObj->solArr[i]);
    fclose(solcsv);
}

void dispSolAsPlot(OdeSolverObject* _solObj){
    gnuplot_ctrl* h1;
    h1 = gnuplot_init();
    gnuplot_resetplot(h1);
    gnuplot_setstyle(h1, "lines");
    gnuplot_plot_xy(h1, _solObj->timeArr, _solObj->solArr, _solObj->Npoints, "Solution");
    
    printf("\n");
#ifdef WIN32
    system("PAUSE");
#else
    system("read -r -p \"Press any key to continue...\" key");
#endif

    gnuplot_close(h1);
}