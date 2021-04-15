#include <iostream>

#include <cmath>
#include <iostream>
#include <vector>
#include <gismo.h>

using namespace gismo;

const double PI = 3.14159265;


int main() {

  std::cout << "Hello\n";
  index_t n = 5;
  index_t m = 5;
  index_t degree = 3;
  std::string output("");
  
  // Adjust values to the minimum required
  degree = math::max( (index_t)(0), degree    );
  n      = math::max(n, degree + 1);
  m      = math::max(m, degree + 1);
  
  gsInfo << "----------------------\n\n"
            << "n: " << n << "\n\n"
            << "m: " << m << "\n\n"
            << "degree: " << degree << "\n\n"
            << "output: " << output << "\n\n"
            << "----------------------\n\n";
  
  // 1. construction of a knot vector for each direction
  gsKnotVector<> kv1(0, 1, n - degree - 1, degree + 1);
  gsKnotVector<> kv2(0, 1, m - degree - 1, degree + 1);
  
  // 2. construction of a basis
  gsTensorBSplineBasis<2, real_t> basis(kv1, kv2);
  
  // 3. construction of a coefficients
  gsMatrix<index_t> greville = basis.anchors();  // <- issues with this line!

  // does the following:
  // anchors() gets inheritied from gsBasis which:
  // - constructs a gsMatrix
  // - calls anchors_into()
  // - which is defined in gsTensorBasis which:
  // - 
  //



  // gsMatrix<> coefs (greville.cols(), 3);
  
  // for (index_t col = 0; col != greville.cols(); col++)
  // {
  //     real_t x = greville(0, col);
  //     real_t y = greville(1, col);
  
  //     coefs(col, 0) = x;
  //     coefs(col, 1) = y;
  //     coefs(col, 2) = math::sin(x * 2 * PI) * math::sin(y * 2 * PI);
  // }
  
  // // 4. putting basis and coefficients toghether
  // gsTensorBSpline<2, real_t>  surface(basis, coefs);
  
  // std::string out = output + "Basis";
  // gsInfo << "Writing the basis to a paraview file: " << out
  //           << "\n\n";
  
  // gsWriteParaview(basis, out);
  
  // gsMesh<> mesh;
  // surface.controlNet(mesh);
  // gsWriteParaview(mesh, out);


  return(0);
}
