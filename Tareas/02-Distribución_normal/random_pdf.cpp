#include <random>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <cmath>

void compute_pdf(int seed, int nsamples, double mu, double sigma, double xmin, double xmax, int nbins);
double teorical_pdf(double x, double mu, double sigma);

int main(int argc, char **argv)
{
  const int SEED = std::atoi(argv[1]);
  const int NSAMPLES = std::atoi(argv[2]);
  const double MU = std::stod(argv[3]);
  const double SIGMA = std::stod(argv[4]);
  const double XMIN = std::stod(argv[5]);
  const double XMAX = std::stod(argv[6]);
  const int NBINS = std::atoi(argv[7]);

  compute_pdf(SEED, NSAMPLES, MU, SIGMA, XMIN, XMAX, NBINS);
}

void compute_pdf(int seed, int nsamples, double mu, double sigma, double xmin, double xmax, int nbins)
{
  // random stuff
  std::mt19937 gen(seed);
  std::normal_distribution<double> dis{mu, sigma};

  // Histogram stuff
  std::vector<int> histogram(nbins, 0); // Vector que almacena las frecuencias
  double width = (xmax - xmin) / nbins; // El ancho de los intervalos del histograma

  for(int n = 0; n < nsamples; ++n) {
    double r = dis(gen);

    // Fill here the counting histogram stuff
    if (r >= xmin && r <= xmax){ 
       int bin_i = static_cast<int>((r - xmin) / width);        // Calcula el intervalo en el que cae r 
       histogram[bin_i]++;                                      // Cuenta los r de cada intervalo
     }
  }
  // Compute and print the pdf
  for(int i = 0; i < nbins; i++) {
    double x = xmin + width * (0.5 + i); // Centro del intervalo i
    double pdf_teo = teorical_pdf(x, mu, sigma);
    double pdf_est = histogram[i] / (nsamples * width);
    std::cout << x << "\t" << pdf_est << "\t" << pdf_teo << "\n";
  }
}

double teorical_pdf(double x, double mu, double sigma)
{
  return (1.0 / (sigma * std::sqrt(2 * M_PI))) * std::exp(-0.5 * std::pow((x - mu) / sigma, 2));
}