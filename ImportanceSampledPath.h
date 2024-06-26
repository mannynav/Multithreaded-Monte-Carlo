
#pragma once


#ifndef IMPORTANCESAMPLEDPATH
#define IMPORTANCESAMPLEDPATH

#include "BrownianMotionPathBase.h"
#include "PseudoFactory.h"

class ImportanceSampledPath : public BrownianMotionPathBase
{

public:

	ImportanceSampledPath(const PseudoFactory& factory);
	void GeneratePath(std::vector<double>& path, boost::mt19937& rng) override;
	std::vector<double> likelihood_ratio() const override
	{
		return W;
	}

private:

	double T_{};
	double N_{};
	double dt_{};

	mutable std::vector<double> W{};

};

#endif