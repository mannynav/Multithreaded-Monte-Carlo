

/*
 *
 * This model is the Displaced Diffusion model for dynamics of the underlying asset.
 * The model is capable of modelling skewed implied volatility structures.
 * Closed form solutions for plain vanilla options are available, see Rebonato 2002.
 *
 */


#pragma once
#include "ModelBase.h"
#include "RandomBase.h"

#ifndef DISPLACEDDIFFUSIONMODEL_H
#define DISPLACEDDIFFUSIONMODEL_H

class DisplacedDiffusionModel : public ModelBase

{
public:
	DisplacedDiffusionModel(PseudoFactory& factory);
	void simulate_paths(int start_idx, int end_idx, Eigen::MatrixXd& paths) const override;
	double Get_MT() const override
	{
		return std::exp(r_ * T_);
	}

private:
	double S0_{};
	double r_{};

	double a_{};			//Displacement parameter
	double sigmaDD_{};

	double drift_{};

	double M_{};
	double N_{};

	double T_{};
	double dt_{};
	double sqrtdt_{};

	std::unique_ptr<BrownianMotionPathBase> path_;
	std::unique_ptr<RandomBase> generator_{};
};
#endif 
