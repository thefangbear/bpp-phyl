//
// File: PhyloBranchRewardForASite.h
// Created by: Laurent Guéguen
// Created on: mercredi 26 septembre 2018, à 16h 15
//

/*
  Copyright or © or Copr. Bio++ Development Team, (November 16, 2004)

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

#ifndef _PHYLOBRANCH_REWARD_FOR_A_SITE_H_
#define _PHYLOBRANCH_REWARD_FOR_A_SITE_H_

#include <Bpp/Numeric/Number.h>
#include <Bpp/Clonable.h>
#include <Bpp/Exceptions.h>

#include "../Tree/PhyloBranch.h"


namespace bpp
{
  /*
   * @brief A branch with countings.
   *
   * WARNING : this class does not know anything about site
   * compression, if any. If there are site patterns, they are
   * available in ProbabilisticSubstitutionReward class.
   *
   */
  
  class PhyloBranchRewardForASite :
    public PhyloBranch
  {
  protected:
    /*
     * @brief rewards are stored by site
     *
     */
    
    double reward_;
    
  public:
    /**
     * @brief Constructors.
     *
     * @warning phyloTree_ does not know the edge exists.
     *
     */
    
    PhyloBranchRewardForASite():
      PhyloBranch(),
      reward_()
    {
    }

    PhyloBranchRewardForASite(double length):
      PhyloBranch(length),
      reward_()
    {
    }

    PhyloBranchRewardForASite(const PhyloBranch& branch):
      PhyloBranch(branch),
      reward_()
    {
    }
    
    /**
     * @brief Copy constructor.
     *
     * @param branch The branch to copy.
     */
    
    PhyloBranchRewardForASite(const PhyloBranchRewardForASite& branch):
      PhyloBranch(branch),
      reward_(branch.reward_)
    {
    }
    
    /**
     * @brief Assignation operator.
     *
     * @param branch the branch to copy.
     * @return A reference toward this branch.
     */

    PhyloBranchRewardForASite& operator=(const PhyloBranchRewardForASite& branch)
    {
      PhyloBranch::operator=(branch);
      reward_ = branch.reward_;
      return *this;
      
    }
    
    PhyloBranchRewardForASite* clone() const { return new PhyloBranchRewardForASite(*this); }
    
    /**
     * @brief destructor. In Graph, nothing is changed.
     *
     */
    
    ~PhyloBranchRewardForASite()
    {
    }

    double getReward()
    {
      return reward_;
    }
    
    void setReward(double reward)
    {
      reward_=reward;
    }
  };

} //end of namespace bpp.

#endif  //_PHYLOBRANCH_REWARD_FOR_A_SITE_H_