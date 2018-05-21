//
// File: GA.cpp
//
// MATLAB Coder version            : 3.3
// C/C++ source code generated on  : 21-May-2018 18:13:20
//

// Include Files
#include "rt_nonfinite.h"
#include "GA.h"
#include "rand.h"
#include "GA_emxutil.h"

// Function Declarations
static void bintodec(const double bins_data[], double limitedRange, double
                     chromesomesize, double decs[6]);
static double cost(const double schedule[6], const double jobs[6], double
                   numberOfMachines);
static void mutate(const double a_data[], const int a_size[2], double anew_data[],
                   int anew_size[2]);
static double rt_powd_snf(double u0, double u1);
static double rt_roundd_snf(double u);

// Function Definitions

//
// Arguments    : const double bins_data[]
//                double limitedRange
//                double chromesomesize
//                double decs[6]
// Return Type  : void
//
static void bintodec(const double bins_data[], double limitedRange, double
                     chromesomesize, double decs[6])
{
  double b_index;
  double divisor;
  int deci;
  double nindex;
  int i3;
  int i4;
  int loop_ub;
  int i5;
  double bin_data[312];
  double generated;

  //  end for evolve
  b_index = 1.0;
  divisor = rt_powd_snf(2.0, chromesomesize) - 1.0;
  for (deci = 0; deci < 6; deci++) {
    nindex = b_index + chromesomesize;
    if (b_index > nindex - 1.0) {
      i3 = 0;
      i4 = 0;
    } else {
      i3 = (int)b_index - 1;
      i4 = (int)(nindex - 1.0);
    }

    loop_ub = i4 - i3;
    for (i5 = 0; i5 < loop_ub; i5++) {
      bin_data[i5] = bins_data[i3 + i5];
    }

    //  get the binary
    generated = 0.0;
    for (loop_ub = 0; loop_ub < i4 - i3; loop_ub++) {
      generated += bin_data[loop_ub] * rt_powd_snf(2.0, (double)(((i4 - i3) -
        loop_ub) - 1));
    }

    b_index = nindex;
    decs[deci] = rt_roundd_snf(generated / divisor * (limitedRange - 1.0)) + 1.0;
  }
}

//
// Arguments    : const double schedule[6]
//                const double jobs[6]
//                double numberOfMachines
// Return Type  : double
//
static double cost(const double schedule[6], const double jobs[6], double
                   numberOfMachines)
{
  double result;
  emxArray_real_T *results;
  int ixstart;
  int n;
  int ix;
  boolean_T exitg1;
  emxInit_real_T(&results, 2);
  ixstart = results->size[0] * results->size[1];
  results->size[0] = 1;
  results->size[1] = (int)numberOfMachines;
  emxEnsureCapacity((emxArray__common *)results, ixstart, sizeof(double));
  n = (int)numberOfMachines;
  for (ixstart = 0; ixstart < n; ixstart++) {
    results->data[ixstart] = 0.0;
  }

  for (ixstart = 0; ixstart < 6; ixstart++) {
    results->data[(int)schedule[ixstart] - 1] += jobs[ixstart];
  }

  ixstart = 1;
  n = results->size[1];
  result = results->data[0];
  if (results->size[1] > 1) {
    if (rtIsNaN(results->data[0])) {
      ix = 2;
      exitg1 = false;
      while ((!exitg1) && (ix <= n)) {
        ixstart = ix;
        if (!rtIsNaN(results->data[ix - 1])) {
          result = results->data[ix - 1];
          exitg1 = true;
        } else {
          ix++;
        }
      }
    }

    if (ixstart < results->size[1]) {
      while (ixstart + 1 <= n) {
        if (results->data[ixstart] > result) {
          result = results->data[ixstart];
        }

        ixstart++;
      }
    }
  }

  emxFree_real_T(&results);
  return result;
}

//
// Arguments    : const double a_data[]
//                const int a_size[2]
//                double anew_data[]
//                int anew_size[2]
// Return Type  : void
//
static void mutate(const double a_data[], const int a_size[2], double anew_data[],
                   int anew_size[2])
{
  int loop_ub;
  int i6;
  double x;
  double b_x;

  //  end for crossover
  //  Mutatation operator
  anew_size[0] = 1;
  anew_size[1] = a_size[1];
  loop_ub = a_size[0] * a_size[1];
  for (i6 = 0; i6 < loop_ub; i6++) {
    anew_data[i6] = a_data[i6];
  }

  for (loop_ub = 0; loop_ub < 2; loop_ub++) {
    x = c_rand() * (double)a_size[1];
    b_x = std::floor(x);
    if ((!rtIsInf(a_data[(int)(b_x + 1.0) - 1] + 1.0)) && (!rtIsNaN(a_data[(int)
          (b_x + 1.0) - 1] + 1.0))) {
      x = std::fmod(a_data[(int)(std::floor(x) + 1.0) - 1] + 1.0, 2.0);
      if (x == 0.0) {
        x = 0.0;
      }
    } else {
      x = rtNaN;
    }

    anew_data[(int)(b_x + 1.0) - 1] = x;
  }
}

//
// Arguments    : double u0
//                double u1
// Return Type  : double
//
static double rt_powd_snf(double u0, double u1)
{
  double y;
  double d0;
  double d1;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = rtNaN;
  } else {
    d0 = std::abs(u0);
    d1 = std::abs(u1);
    if (rtIsInf(u1)) {
      if (d0 == 1.0) {
        y = 1.0;
      } else if (d0 > 1.0) {
        if (u1 > 0.0) {
          y = rtInf;
        } else {
          y = 0.0;
        }
      } else if (u1 > 0.0) {
        y = 0.0;
      } else {
        y = rtInf;
      }
    } else if (d1 == 0.0) {
      y = 1.0;
    } else if (d1 == 1.0) {
      if (u1 > 0.0) {
        y = u0;
      } else {
        y = 1.0 / u0;
      }
    } else if (u1 == 2.0) {
      y = u0 * u0;
    } else if ((u1 == 0.5) && (u0 >= 0.0)) {
      y = std::sqrt(u0);
    } else if ((u0 < 0.0) && (u1 > std::floor(u1))) {
      y = rtNaN;
    } else {
      y = pow(u0, u1);
    }
  }

  return y;
}

//
// Arguments    : double u
// Return Type  : double
//
static double rt_roundd_snf(double u)
{
  double y;
  if (std::abs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = std::floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = std::ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

//
// Arguments    : const double jobList[6]
//                double NumberOfMachines
//                double MaxGen
//                double fitness
//                double fitold
//                double range
//                double sol
//                double pop
//                double limitedRange
//                double solnew
//                double popnew
//                double userdefinedn
//                double chromesomesize
//                emxArray_real_T *costs
//                double schedule[6]
// Return Type  : void
//
void GA(const double jobList[6], double NumberOfMachines, double MaxGen, double,
        double, double, double, double, double, double, double, double, double,
        emxArray_real_T *costs, double schedule[6])
{
  double b_range[2];
  int s_size_idx_1;
  int i0;
  double di;
  char s_data[52];
  int j;
  boolean_T exitg1;
  int firstcol;
  double olddi;
  boolean_T p;
  emxArray_real_T *b_popnew;
  double y[2];
  int ix;
  int loop_ub;
  int i;
  emxArray_real_T *bestsol;
  double pop_data[312];
  double b_bestsol[6];
  double b_solnew[600];
  emxArray_real_T *b_pop;
  double x;
  double ii;
  double b_sol[600];
  double jj;
  signed char tmp_data[100];
  int i1;
  double sol_data[600];
  double a_data[312];
  int pop_size[2];
  double b_data[312];
  double b_tmp_data[312];
  int tmp_size[2];

  //  Genetic Algorithm (Simple Demo) Matlab/Octave Program
  //  Written by X S Yang (Cambridge University)
  //  Modified by Gary Li (University of Waterloo) 2014
  //  Usage: gasimple or gasimple('x*exp(-x)');
  // This program is modified to satify the Job Scheduling problem
  // For ECE457A, Unitersity of Waterloo, Summer, 2014
  // costs, Best Solution
  b_range[0] = 1.0;
  b_range[1] = NumberOfMachines;

  //  Range/Domain
  //  Initializing the parameters
  //    rand('state' ,0'); % Reset the random generator
  //  Population size
  //    MaxGen=100; % Max number of generations
  //  counter
  //  number of mutation sites
  //  Crossover probability
  //  Mutation probability
  //  Update the max generation number if max generation is given
  //    if nargin>1,
  //      MaxGen=maxGen;
  //      jobList=jobs;
  //      NumberOfMachines=numberOfMachines;
  //    end
  s_size_idx_1 = 52;
  for (i0 = 0; i0 < 52; i0++) {
    s_data[i0] = '0';
  }

  di = NumberOfMachines;
  j = 52;
  exitg1 = false;
  while ((!exitg1) && (j > 0)) {
    olddi = di;
    di = std::floor(di / 2.0);
    if (2.0 * di < olddi) {
      s_data[j - 1] = '1';
    }

    if (di > 0.0) {
      j--;
    } else {
      exitg1 = true;
    }
  }

  firstcol = 52;
  j = 1;
  exitg1 = false;
  while ((!exitg1) && (j <= 51)) {
    p = false;
    if (s_data[j - 1] != '0') {
      p = true;
    }

    if (p) {
      firstcol = j;
      exitg1 = true;
    } else {
      j++;
    }
  }

  if (firstcol > 1) {
    s_size_idx_1 = 53 - firstcol;
  }

  emxInit_real_T(&b_popnew, 2);

  //  String length (bits)
  // user defined n
  //  Generating the initial population
  //  String length=nsbit+l with pop(:,l) for the Sign
  // pop=rand(np,nsbit)>0.5;
  //  end for gasimple
  //  All the sub functions
  //  generation of the initial population
  b_rand(6.0 * (double)s_size_idx_1, b_popnew);
  i0 = 100 * b_popnew->size[1];
  for (firstcol = 0; firstcol < i0; firstcol++) {
    b_popnew->data[firstcol] = std::floor(b_popnew->data[firstcol] * 2.0);
  }

  //  fitness array
  //    Display the shape of the function
  // x=range(1):0.1:range(2);
  // plot(x,felement(x,userdefinedn));
  //  Initialize solution <- initial population
  for (firstcol = 0; firstcol < 2; firstcol++) {
    y[firstcol] = std::abs(b_range[firstcol]);
  }

  firstcol = 1;
  di = y[0];
  if (rtIsNaN(y[0])) {
    ix = 2;
    exitg1 = false;
    while ((!exitg1) && (ix < 3)) {
      firstcol = 2;
      if (!rtIsNaN(y[1])) {
        di = y[1];
        exitg1 = true;
      } else {
        ix = 3;
      }
    }
  }

  if ((firstcol < 2) && (y[1] > di)) {
    di = y[1];
  }

  i0 = costs->size[0];
  costs->size[0] = (int)MaxGen;
  emxEnsureCapacity((emxArray__common *)costs, i0, sizeof(double));
  loop_ub = (int)MaxGen;
  for (i0 = 0; i0 < loop_ub; i0++) {
    costs->data[i0] = 0.0;
  }

  // TODO:populate row
  for (i = 0; i < 100; i++) {
    loop_ub = b_popnew->size[1];
    for (i0 = 0; i0 < loop_ub; i0++) {
      pop_data[i0] = b_popnew->data[i + b_popnew->size[0] * i0];
    }

    bintodec(pop_data, di, (double)s_size_idx_1, b_bestsol);
    for (i0 = 0; i0 < 6; i0++) {
      b_solnew[i + 100 * i0] = b_bestsol[i0];
    }
  }

  emxInit_real_T(&bestsol, 2);
  i0 = bestsol->size[0] * bestsol->size[1];
  bestsol->size[0] = (int)MaxGen;
  bestsol->size[1] = 6;
  emxEnsureCapacity((emxArray__common *)bestsol, i0, sizeof(double));
  loop_ub = (int)MaxGen * 6;
  for (i0 = 0; i0 < loop_ub; i0++) {
    bestsol->data[i0] = 0.0;
  }

  emxInit_real_T(&b_pop, 2);

  // Record as the history
  i0 = b_pop->size[0] * b_pop->size[1];
  b_pop->size[0] = 100;
  b_pop->size[1] = b_popnew->size[1];
  emxEnsureCapacity((emxArray__common *)b_pop, i0, sizeof(double));
  loop_ub = b_popnew->size[0] * b_popnew->size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    b_pop->data[i0] = b_popnew->data[i0];
  }

  //  Start the evolution loop
  for (i = 0; i < (int)MaxGen; i++) {
    //  Record as the history
    for (firstcol = 0; firstcol < 100; firstcol++) {
      loop_ub = b_popnew->size[1] - 1;
      for (i0 = 0; i0 <= loop_ub; i0++) {
        b_pop->data[firstcol + b_pop->size[0] * i0] = b_popnew->data[firstcol +
          b_popnew->size[0] * i0];
      }

      for (i0 = 0; i0 < 6; i0++) {
        b_sol[firstcol + 100 * i0] = b_solnew[firstcol + 100 * i0];
      }
    }

    for (j = 0; j < 100; j++) {
      //  Crossover pair
      di = 100.0 * c_rand();
      x = std::floor(di);
      ii = std::floor(di) + 1.0;
      di = 100.0 * c_rand();
      olddi = std::floor(di);
      jj = std::floor(di) + 1.0;

      //  Cross over
      if (0.95 > c_rand()) {
        loop_ub = b_pop->size[1];
        for (i0 = 0; i0 < loop_ub; i0++) {
          a_data[i0] = b_pop->data[((int)(x + 1.0) + b_pop->size[0] * i0) - 1];
        }

        loop_ub = b_pop->size[1];
        for (i0 = 0; i0 < loop_ub; i0++) {
          b_data[i0] = b_pop->data[((int)(olddi + 1.0) + b_pop->size[0] * i0) -
            1];
        }

        //  end for bintodec
        //  Crossover operator
        //  generating a random crossover point
        i0 = b_pop->size[1];
        di = ((double)i0 - 1.0) * c_rand();
        x = std::floor(di);
        di = std::floor(di) + 1.0;
        i0 = b_pop->size[1];
        if (di + 1.0 > i0) {
          i0 = 1;
          i1 = 0;
        } else {
          i0 = (int)(di + 1.0);
          i1 = b_pop->size[1];
        }

        firstcol = b_pop->size[1];
        if (di + 1.0 > firstcol) {
          firstcol = 1;
          ix = 0;
        } else {
          firstcol = (int)(di + 1.0);
          ix = b_pop->size[1];
        }

        loop_ub = (int)(x + 1.0);
        for (s_size_idx_1 = 0; s_size_idx_1 < loop_ub; s_size_idx_1++) {
          b_popnew->data[((int)ii + b_popnew->size[0] * s_size_idx_1) - 1] =
            a_data[s_size_idx_1];
        }

        loop_ub = i1 - i0;
        for (i1 = 0; i1 <= loop_ub; i1++) {
          b_popnew->data[((int)ii + b_popnew->size[0] * (i1 + (int)(x + 1.0))) -
            1] = b_data[(i0 + i1) - 1];
        }

        loop_ub = (int)(x + 1.0);
        for (i0 = 0; i0 < loop_ub; i0++) {
          b_popnew->data[((int)jj + b_popnew->size[0] * i0) - 1] = b_data[i0];
        }

        loop_ub = ix - firstcol;
        for (i0 = 0; i0 <= loop_ub; i0++) {
          b_popnew->data[((int)jj + b_popnew->size[0] * (i0 + (int)(x + 1.0))) -
            1] = a_data[(firstcol + i0) - 1];
        }

        //  Evaluate the new pairs
        //  end for init_gen
        //  Evolving the new generation
        // TODO: cost(schedule, Jobs, numberOfMachine)
        //  Convert a binary string into a decimal number
        //  end for init_gen
        //  Evolving the new generation
        // TODO: cost(schedule, Jobs, numberOfMachine)
        //  Convert a binary string into a decimal number
      }

      //  Mutation at n sites
      if (0.05 > c_rand()) {
        di = 100.0 * c_rand();
        x = std::floor(di);
        loop_ub = b_pop->size[1];
        pop_size[0] = 1;
        pop_size[1] = loop_ub;
        for (i0 = 0; i0 < loop_ub; i0++) {
          pop_data[i0] = b_pop->data[((int)(x + 1.0) + b_pop->size[0] * i0) - 1];
        }

        mutate(pop_data, pop_size, b_tmp_data, tmp_size);
        i0 = (int)(std::floor(di) + 1.0);
        loop_ub = tmp_size[1];
        for (i1 = 0; i1 < loop_ub; i1++) {
          b_popnew->data[(i0 + b_popnew->size[0] * i1) - 1] =
            b_tmp_data[tmp_size[0] * i1];
        }

        //  end for init_gen
        //  Evolving the new generation
        // TODO: cost(schedule, Jobs, numberOfMachine)
        //  Convert a binary string into a decimal number
      }
    }

    //  end for j
    //  Record the current best
    s_size_idx_1 = 0;
    for (firstcol = 0; firstcol < 100; firstcol++) {
      s_size_idx_1++;
    }

    ix = 0;
    for (firstcol = 0; firstcol < 100; firstcol++) {
      tmp_data[ix] = (signed char)(firstcol + 1);
      ix++;
    }

    for (i0 = 0; i0 < 6; i0++) {
      for (i1 = 0; i1 < s_size_idx_1; i1++) {
        sol_data[i1 + s_size_idx_1 * i0] = b_sol[(tmp_data[i1] + 100 * i0) - 1];
      }
    }

    for (i0 = 0; i0 < 6; i0++) {
      bestsol->data[i + bestsol->size[0] * i0] = sol_data[s_size_idx_1 * i0];
    }

    for (i0 = 0; i0 < 6; i0++) {
      b_bestsol[i0] = bestsol->data[i + bestsol->size[0] * i0];
    }

    costs->data[i] = cost(b_bestsol, jobList, NumberOfMachines);
  }

  emxFree_real_T(&b_pop);
  emxFree_real_T(&b_popnew);

  //  end for i
  //  Display results
  // set(gcf,'color','w');
  // subplot (2,1,1);
  // plot(bestsol);
  // title('Plot of best solution of each generation');
  // subplot(2,1,2);
  // plot(bestfun);
  // title('Fitness');
  // output
  firstcol = bestsol->size[0];
  for (i0 = 0; i0 < 6; i0++) {
    schedule[i0] = bestsol->data[(firstcol + bestsol->size[0] * i0) - 1];
  }

  emxFree_real_T(&bestsol);

  // costOutput=cost(schedule, jobs, numberOfMachines);
}

//
// File trailer for GA.cpp
//
// [EOF]
//
