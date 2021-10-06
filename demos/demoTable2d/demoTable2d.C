//    Copyright (C) 2021 ttsyshmz

#include "fvCFD.H"
#include "interpolation2DTable.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //
/*
                    secondary
                   |  0.1   0.2   0.3
              -----+-----------------
              0.02 |   A     B     C
     primary  0.04 |   D     E     F
              0.06 |   G     H     I

file:
        (
            (
                0.02
                (
                    (0.1    A)
                    (0.2    B)
                    (0.3    C)
                )
            )
            (
                0.04
                (
                    (0.1    D)
                    (0.2    E)
                    (0.3    F)
                )
            )
            (
                0.06
                (
                    (0.1    G)
                    (0.2    H)
                    (0.3    I)
                )
            )
        );
*/
int main(int argc, char *argv[])
{
    #include "setRootCase.H"
    #include "autoPtr.H"

    // * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

    autoPtr<interpolation2DTable<vector>> table;
    table.reset(new interpolation2DTable<vector>("./table.txt"));
    Info << table()(0.02, 0.15) << endl;

    Info<< "End\n" << endl;

    return 0;
}
// ************************************************************************* //
