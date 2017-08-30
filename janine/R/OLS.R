#' Compute the OLS esstimator
#'
#' @param X A matrix
#' @param y A vector
#' @return a vector of coefficients
#' @examples
#' n <- 100; p <- 10
#' X <- matrix(rnorm(n*p), n, p)
#' beta <- runif(p, 1, 2) * sample(c(-1,1), p, rep=TRUE)
#' y <- X %*% beta + rnorm(n)
#' OLS(X,y)
#' @export


OLS <- function(X,y) {
  beta.hat <- chol2inv(chol(crossprod(X))) %*% crossprod(X,y)
  beta.hat
}
