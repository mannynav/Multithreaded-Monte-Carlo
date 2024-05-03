#pragma once

#include "ModelBase.h"
#include "PseudoFactory.h"
#include "RandomBase.h"
#include "HestonDiscretizationBase.h"

#ifndef HESTONMODEL_H
#define HESTONMODEL_H

class PseudoFactory;

class HestonModel : public ModelBase

{
public:
	HestonModel(double S0, double r, double sigma);
	HestonModel(PseudoFactory& factory);
	~HestonModel() = default;
	void simulate_paths(int start_idx, int end_idx, Eigen::MatrixXd& paths) const override;
	std::vector<double> get_likelihood_ratio() const override
	{
		std::vector<double> W;
		return W;
	}
	double Get_MT() const override
	{
		return std::exp(r_ * T_);
	}

private:
	double S0_{};
	double r_{};
	double sigma_{};

	double V_0_{};
	double corr_{};
	double volvol_{};
	double meanreversion_{};
	double ltmean_{};
	double PsiC_{};

	double k0_{};
	double k1_{};
	double k2_{};

	double y1_ = 0.5;
	double y2_ = 0.5;

	double expression_;
	double sqrt_expression_;
	double delta_;
	double c_;

	//HestoDiscretizationBase* descritization;

	mutable std::vector<double> cir_path_;

	double dt_{};
	double N_{};
	double T_{};

	std::unique_ptr<RandomBase> generator_{};
	std::vector<double> generate_CIR_path(boost::mt19937 & rng) const;

};
#endif // HESTONMODEL_H