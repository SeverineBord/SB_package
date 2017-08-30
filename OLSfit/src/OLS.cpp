#include <RcppArmadillo.h>

using namespace Rcpp;
// [[Rcpp::depends(RcppArmadillo)]]

using namespace Rcpp;
using namespace arma;

//' Compute the OLS esstimator
//'
//' @param X A matrix
//' @param y A vector
//' @return a vector of coefficients
//' @examples
//' n <- 100; p <- 10
//' X <- matrix(rnorm(n*p), n, p)
//' beta <- runif(p, 1, 2) * sample(c(-1,1), p, rep=TRUE)
//' y <- X %*% beta + rnorm(n)
//' OLSfast(X,y)
//' @export
// [[Rcpp::export]]
NumericVector OLScpp(const arma::mat X, const arma::vec y) {
  return wrap( inv_sympd(X.t() * X) * X.t() * y ) ;
}
