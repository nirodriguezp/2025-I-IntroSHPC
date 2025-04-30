#include <random>
#include <iostream>
#include <cstdlib>
#include <vector>

void compute_pdf(int seed, int nsamples, double mu, double sigma, double xmin, double xmax, int nbins);

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
  std::vector<int> histogram(nbins);
  double x_width = (xmax - xmin) / nbins;

  for(int n = 0; n < nsamples; ++n) {
    double r = dis(gen);

    // TODO: fill here the counting histogram stuff
    for(int i = 0; i < nbins; i++)
    {
        if (r >= xmin + i * x_width && r < xmin + (i+1) * x_width){
            histogram[i] += 1;
        }
    }
  }
  // TODO: compute and print the pdf
  for(int i = 0; i < nbins; i++) {

    std::cout << xmin + x_width * (0.5 + i) << "\t" << histogram[i] << "\n";
  }
}