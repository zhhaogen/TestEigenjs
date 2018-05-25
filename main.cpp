#include <iostream>
#include <string> 
#include <Eigen/Dense>
using Eigen::MatrixXd;
using std::string;
extern "C" {
	MatrixXd newMatrixXd(int aCols,int aRows,double* aRaw)
	{
		 MatrixXd m(aCols,aRows);
		 for(int i=0;i<aCols;i++)
		 {
			 for(int j=0;j<aRows;j++)
			 {
				 m(i,j) =aRaw[i*aRows+j];   
			 }
		}
		return m;
	}
	const char* printMatrixXd(int aCols,int aRows,double* aRaw)
	{
		 std::cout <<"aCols="<< aCols <<",aRows="<< aRows<< std::endl;
		 MatrixXd m(aCols,aRows);
		 for(int i=0;i<aCols;i++)
		 {
			 for(int j=0;j<aRows;j++)
			 {
				 int index=i*aRows+j;
				 m(i,j) =aRaw[index];  
				std::cout <<index<<","<<"m("<<i<<","<<j<<")="<<m(i,j)<< std::endl;
			 }
		 }
		std::stringstream str;
		str << m;
		// std::cout << m << std::endl; 
		return str.str().c_str() ;
	}
	
	const char* addMatrixXd(int aCols,int aRows,double* aRaw,int bCols,int bRows,double* bRaw)
	{
		MatrixXd  A=newMatrixXd(aCols,aRows,aRaw);
		MatrixXd  B=newMatrixXd(bCols,bRows,bRaw);
		MatrixXd C=A+B;
		std::stringstream str;
		str << C;
		std::cout << A<< std::endl<<"+"<< std::endl<<B<< std::endl<<"="<< std::endl<<C << std::endl; 
		return str.str().c_str() ;
	}
	const char* subMatrixXd(int aCols,int aRows,double* aRaw,int bCols,int bRows,double* bRaw)
	{
		MatrixXd  A=newMatrixXd(aCols,aRows,aRaw);
		MatrixXd  B=newMatrixXd(bCols,bRows,bRaw);
		MatrixXd C=A-B;
		std::stringstream str;
		str << C; 
		std::cout << A<< std::endl<<"-"<< std::endl<<B<< std::endl<<"="<< std::endl<<C<< std::endl; 
		return str.str().c_str() ;
	}
	const char* trMatrixXd(int aCols,int aRows,double* aRaw)
	{
		MatrixXd  A=newMatrixXd(aCols,aRows,aRaw); 
		MatrixXd C=A.transpose();
		std::stringstream str;
		str << C; 
		std::cout << A<< std::endl<<"transpose"<< std::endl<<C<< std::endl; 
		return str.str().c_str() ;
	}
	const char* muiltMatrixXd(int aCols,int aRows,double* aRaw,int bCols,int bRows,double* bRaw)
	{
		MatrixXd  A=newMatrixXd(aCols,aRows,aRaw);
		MatrixXd  B=newMatrixXd(bCols,bRows,bRaw);
		MatrixXd C=A*B;
		std::stringstream str;
		str << C; 
		std::cout << A<< std::endl<<"*"<< std::endl<<B<< std::endl<<"="<< std::endl<<C<< std::endl; 
		return str.str().c_str() ;
	}
	const char* inverseMatrixXd(int aCols,int aRows,double* aRaw)
	{
		MatrixXd  A=newMatrixXd(aCols,aRows,aRaw); 
		MatrixXd C=A.inverse();
		std::stringstream str;
		str << C; 
		std::cout << A<< std::endl<<"inverse"<< std::endl<<C<< std::endl; 
		return str.str().c_str() ;
	}
	const char* adjointMatrixXd(int aCols,int aRows,double* aRaw)
	{
		MatrixXd  A=newMatrixXd(aCols,aRows,aRaw); 
		MatrixXd C=A.adjoint();
		std::stringstream str;
		str << C; 
		std::cout << A<< std::endl<<"adjoint"<< std::endl<<C<< std::endl; 
		return str.str().c_str() ;
	}
	const char* traceMatrixXd(int aCols,int aRows,double* aRaw )
	{
		MatrixXd  A=newMatrixXd(aCols,aRows,aRaw); 
		double C=A.trace();
		std::stringstream str;
		str << C; 
		std::cout << A<< std::endl<<"trace"<< std::endl<<C<< std::endl; 
		return str.str().c_str() ;
	}
	const char* detMatrixXd(int aCols,int aRows,double* aRaw)
	{
		MatrixXd  A=newMatrixXd(aCols,aRows,aRaw); 
		double C=A.determinant();
		std::stringstream str;
		str << C; 
		std::cout << A<< std::endl<<"det"<< std::endl<<C<< std::endl; 
		return str.str().c_str() ;
	}
	const char* rankMatrixXd(int aCols,int aRows,double* aRaw)
	{
		MatrixXd  A=newMatrixXd(aCols,aRows,aRaw); 
		Eigen::FullPivLU<MatrixXd> lu_decomp(A); 
		double C=lu_decomp.rank();
		std::stringstream str;
		str << C; 
		std::cout << A<< std::endl<<"LU rank"<< std::endl<<C<< std::endl; 
		return str.str().c_str() ;
	}
}