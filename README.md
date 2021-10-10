# GMM
 A Gaussian Mixture Model library featuring BIC and AIC. The majority of the methods in this library are ported to C++ from the GaussianMixture() implementation in the Python's scikit-learn (https://scikit-learn.org/stable/modules/generated/sklearn.mixture.GaussianMixture.html). The currently suppoted covariance in this implementation is "full" only. The included kmeans library was written by "aditya1601" and is freely available on https://github.com/aditya1601/kmeans-clustering-cpp/blob/master/kmeans.cpp.

 For using this GaussianMixture library, simply download and place the three header files in your C++ source files' location, then include GaussianMixture.h in your project.
 A sample usage in illustrated in GMM.cpp

If you wish to use or evaluate this project, please cite:
Matar J., El Khoury H., Charr JC., Guyeux C., Chretien S., "Optimized spectral clustering methods for potentially divergent biological sequences", unpublished, 2021.
