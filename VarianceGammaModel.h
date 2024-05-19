#pragma once

#include "ModelBase.h"
#include "RandomBase.h"

#ifndef VARIANCEGAMMAMODEL_H
#define VARIANCEGAMMAMODEL_H


class VarianceGammaModel : public ModelBase

{
public:
	
	VarianceGammaModel(PseudoFactory& factory);
	~VarianceGammaModel() = default;
	Eigen::MatrixXd simulate_paths(int start_idx, int end_idx, Eigen::MatrixXd& paths) const override;
	double Get_MT() const override
	{
		return std::exp(r_ * T_);
	}

private:
	double s0_{};
	double r_{};

	double mu_Vg_{};
	double theta_{};
	double omega_{};
	double beta_{};
	double sigmaVg_{};

	double dt_{};
	double N_{};
	double T_{};

	std::unique_ptr<BrownianMotionPathBase> path_{};
	std::unique_ptr<RandomBase> generator_{};
};
#endif // GBMMODEL_H
