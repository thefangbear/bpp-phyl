//
// File: MixedSubstitutionModel.cpp
// Created by: Laurent Gueguen
//

/*
  Copyright or © or Copr. CNRS, (November 16, 2004)

  This software is a computer program whose purpose is to provide classes
  for phylogenetic data analysis.

  This software is governed by the CeCILL  license under French law and
  abiding by the rules of distribution of free software.  You can  use,
  modify and/ or redistribute the software under the terms of the CeCILL
  license as circulated by CEA, CNRS and INRIA at the following URL
  "http://www.cecill.info".

  As a counterpart to the access to the source code and  rights to copy,
  modify and redistribute granted by the license, users are provided only
  with a limited warranty  and the software's author,  the holder of the
  economic rights,  and the successive licensors  have only  limited
  liability.

  In this respect, the user's attention is drawn to the risks associated
  with loading,  using,  modifying and/or developing or reproducing the
  software by the user in light of its specific status of free software,
  that may mean  that it is complicated to manipulate,  and  that  also
  therefore means  that it is reserved for developers  and  experienced
  professionals having in-depth computer knowledge. Users are therefore
  encouraged to load and test the software's suitability as regards their
  requirements in conditions enabling the security of their systems and/or
  data to be ensured and,  more generally, to use and operate it in the
  same conditions as regards security.

  The fact that you are presently reading this means that you have had
  knowledge of the CeCILL license and that you accept its terms.
*/

#include "MixedSubstitutionModel.h"

#include <string>

using namespace bpp;
using namespace std;


MixedSubstitutionModel::MixedSubstitutionModel(
                                               const Alphabet* alpha,
                                               const std::string& prefix): AbstractSubstitutionModel(alpha, "")
{
  for (unsigned int i=0;i<size_;i++){
    for (unsigned int j=0; j<size_;j++){
      generator_(i,j)=0;
      leftEigenVectors_(i,j)=0;
      rightEigenVectors_(i,j)=0;
    }
    eigenValues_[i]=0;
  }
  eigenDecompose_=false;
}

MixedSubstitutionModel::MixedSubstitutionModel(const MixedSubstitutionModel& msm) :
  AbstractSubstitutionModel(msm)
{
}

MixedSubstitutionModel& MixedSubstitutionModel::operator=(const MixedSubstitutionModel& msm)
{
  AbstractSubstitutionModel::operator=(msm);
  return *this;
}


MixedSubstitutionModel::~MixedSubstitutionModel()
{
}

void MixedSubstitutionModel::setFreq(std::map<int,double>& m)
{
  throw Exception("setFreq method is not available for MixtureOfSubstitutionModels.");
}
