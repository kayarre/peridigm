//! \file Peridigm_IsotropicHardeningPlasticBondAssociatedCorrespondenceMaterial.hpp

//@HEADER
// ************************************************************************
//
//                             Peridigm
//                 Copyright (2011) Sandia Corporation
//
// Under the terms of Contract DE-AC04-94AL85000 with Sandia Corporation,
// the U.S. Government retains certain rights in this software.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are
// met:
//
// 1. Redistributions of source code must retain the above copyright
// notice, this list of conditions and the following disclaimer.
//
// 2. Redistributions in binary form must reproduce the above copyright
// notice, this list of conditions and the following disclaimer in the
// documentation and/or other materials provided with the distribution.
//
// 3. Neither the name of the Corporation nor the names of the
// contributors may be used to endorse or promote products derived from
// this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY SANDIA CORPORATION "AS IS" AND ANY
// EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
// PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL SANDIA CORPORATION OR THE
// CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
// EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
// PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
// PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
// LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
// NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
// SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
// Questions?
// David J. Littlewood   djlittl@sandia.gov
// John A. Mitchell      jamitch@sandia.gov
// Michael L. Parks      mlparks@sandia.gov
// Stewart A. Silling    sasilli@sandia.gov
//
// ************************************************************************
//@HEADER

#ifndef PERIDIGM_ISOTROPICHARDENINGPLASTICBONDASSOCIATEDCORRESPONDENCEMATERIAL_HPP
#define PERIDIGM_ISOTROPICHARDENINGPLASTICBONDASSOCIATEDCORRESPONDENCEMATERIAL_HPP

#include "Peridigm_BondAssociatedCorrespondenceMaterial.hpp"

namespace PeridigmNS {

  class IsotropicHardeningPlasticBondAssociatedCorrespondenceMaterial : public BondAssociatedCorrespondenceMaterial{
  public:

    //! Constructor.
    IsotropicHardeningPlasticBondAssociatedCorrespondenceMaterial(const Teuchos::ParameterList & params);

    //! Destructor.
    virtual ~IsotropicHardeningPlasticBondAssociatedCorrespondenceMaterial();

    //! Return name of material type
    virtual std::string Name() const { return("Isotropic Hardening Plastic Bond Associated Correspondence"); }

    //! Initialize the derived class
    virtual void initialize(const double dt, 
                            const int numOwnedPoints, 
                            const int* ownedIDs,
                            const int* neighborhoodList,
                            PeridigmNS::DataManager& dataManager);

    //! Evaluate the Cauchy stress.
    virtual void computeCauchyStress(const double dt,
                                     const int numOwnedPoints,
                                     const int* neighborhoodList,
                                     PeridigmNS::DataManager& dataManager) const;

    //! Returns the requested material property
    //! A dummy method here.
    virtual double lookupMaterialProperty(const std::string keyname) const {return 0.0;}


  protected:

    string m_hardeningRule;

    double m_yieldStress;
    double m_hardeningStrainConstant; 
    double m_hardeningExponent;

    double m_initialYieldStress;
    double m_saturatedYieldStress;
    double m_exponentialConstant;
    double m_linearConstant;

    // field spec ids for all relevant data
    int m_unrotatedCauchyStressFieldId;
    int m_vonMisesStressFieldId;
    int m_equivalentPlasticStrainFieldId;
    int m_stressTriaxialityFieldId;
    
    int m_bondLevelUnrotatedRateOfDeformationXXFieldId;
    int m_bondLevelUnrotatedRateOfDeformationXYFieldId;
    int m_bondLevelUnrotatedRateOfDeformationXZFieldId;
    int m_bondLevelUnrotatedRateOfDeformationYXFieldId;
    int m_bondLevelUnrotatedRateOfDeformationYYFieldId;
    int m_bondLevelUnrotatedRateOfDeformationYZFieldId;
    int m_bondLevelUnrotatedRateOfDeformationZXFieldId;
    int m_bondLevelUnrotatedRateOfDeformationZYFieldId;
    int m_bondLevelUnrotatedRateOfDeformationZZFieldId;
    int m_bondLevelUnrotatedCauchyStressXXFieldId;
    int m_bondLevelUnrotatedCauchyStressXYFieldId;
    int m_bondLevelUnrotatedCauchyStressXZFieldId;
    int m_bondLevelUnrotatedCauchyStressYXFieldId;
    int m_bondLevelUnrotatedCauchyStressYYFieldId;
    int m_bondLevelUnrotatedCauchyStressYZFieldId;
    int m_bondLevelUnrotatedCauchyStressZXFieldId;
    int m_bondLevelUnrotatedCauchyStressZYFieldId;
    int m_bondLevelUnrotatedCauchyStressZZFieldId;
    int m_bondLevelVonMisesStressFieldId;
    int m_bondLevelEquivalentPlasticStrainFieldId;
    int m_bondLevelStressTriaxialityFieldId;

  };
}

#endif // PERIDIGM_ISOTROPICHARDENINGPLASTICBONDASSOCIATEDCORRESPONDENCEMATERIAL_HPP
