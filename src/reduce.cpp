#include <algorithm>
#include <functional>
#include <Rcpp.h>
using namespace Rcpp;

// [[Rcpp::export]]
Rcpp::IntegerVector iota(const int& x = 10) {
    std::vector<int> indices(x);
    std::ranges::iota(indices.begin(), indices.end(), 0);
    return Rcpp::wrap(indices);
}
