#include <algorithm>
#include <functional>
#include <Rcpp.h>
using namespace Rcpp;

// [[Rcpp::export]]
Rcpp::IntegerVector iota(const int& x = 10) {

    #if __cplusplus == 202302L
        Rcpp::Rcout << "Hello from C++23" << std::endl;
        std::vector<int> indices(x);
        std::ranges::iota(indices.begin(), indices.end(), 0);
        return Rcpp::wrap(indices);
    #endif

    #if __cplusplus == 202002L
        Rcpp::Rcout << "Hello from C++20" << std::endl;
        std::vector<int> indices(x);
        std::iota(indices.begin(), indices.end(), 0);
        return Rcpp::wrap(indices);
    #endif

    #if __cplusplus == 201703L
        Rcpp::Rcout << "Hello from C++17" << std::endl;
        std::vector<int> indices(x);
        std::iota(indices.begin(), indices.end(), 0);
        return Rcpp::wrap(indices);
    #endif
}
