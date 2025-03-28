#include <algorithm>
#include <functional>
#include <Rcpp.h>
#ifdef _OPENMP
  #include <omp.h>
#endif
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



// [[Rcpp::export]]
Rcpp::List checkOpenMP() {
   

    bool openmp_available = false;
    int max_threads = NA_INTEGER;
    int num_procs   = NA_INTEGER;
    #ifdef _OPENMP
        openmp_available = true;
        max_threads = omp_get_max_threads();
        num_procs   = omp_get_num_procs();
    #endif

    return Rcpp::List::create(
        Rcpp::Named("openmp_available")  = openmp_available,
        Rcpp::Named("max_threads")       = max_threads,
        Rcpp::Named("num_procs")         = num_procs
    );
}
