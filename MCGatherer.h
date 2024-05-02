#pragma once
#include <utility>
#include <Eigen/Dense>

class ImportanceSampling;
class ModelBase;


class MCGatherer
{

public:
	virtual ~MCGatherer() {}

	virtual std::pair<double, double> accumulate(const Eigen::VectorXd& payoffs, const ModelBase& model) const
	{
		
		//std::vector<double> RN = model.get_likelihood_ratio();

		//Eigen::VectorXd newPayoffs = Eigen::VectorXd(payoffs.size());
		//for (int i = 0; i < payoffs.size(); i++)
		//{
		//	newPayoffs[i] = payoffs[i] * RN[i];
		//}
		//

		////payoffs for IS
		//double mean_payoff = newPayoffs.mean();

		double mean_payoff = payoffs.mean();

		double sum_squared_devs = 0.0;
		for (double value : payoffs) {
			sum_squared_devs += std::pow(value - mean_payoff, 2);
		}

		double variance = sum_squared_devs / (payoffs.size() - 1); // Unbiased sample variance
		double std_deviation = std::sqrt(variance);
		double standard_error = std_deviation / std::sqrt(payoffs.size());

		std::pair<double, double> results{ mean_payoff,standard_error };

		return results;
	}

private:


};