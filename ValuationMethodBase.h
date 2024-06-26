#pragma once


#ifndef ValuationMethodBaseH
#define ValuationMethodBaseH


class OptionBase;
class ModelBase;
class TermStructureBase;



class ValuationMethodBase
{
public:
    virtual ~ValuationMethodBase() {}
    virtual void run(const OptionBase& opt, const ModelBase& gbm, const TermStructureBase& ts) = 0;
    virtual void OutputResults(const TermStructureBase& ts, const ModelBase& model) const = 0;
};


#endif