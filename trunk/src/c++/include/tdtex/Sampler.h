#ifndef TDTEX_SAMPLER
#define TDTEX_SAMPLER

#include <string>
#include <set>
#include <map>
#include "rped/rped.h"
#include "error/errorstream.h"
#include "tdtex/Configuration.h"
#include "tdtex/TransmissionTables.h"
#include "tdtex/ScoreCalculator.h"

namespace SAGE  {
namespace TDTEX {

/** \class Sampler
  *
  */
class Sampler
{
public:

  /// @name Constructor
  //@{
  
    ///
    /// Constructor.
    /// \param err The errorstream for this object
    Sampler(const Configuration & config, const RPED::MultiPedigree & mp, MPED::SexCode sex, cerrorstream& err);

    Sampler(const Sampler & other);
    
  //@}

  /// @name Misc
  //@{
  
    ///
    /// Returns the multipedigree on the basis of which this Sampler was constructed.
    const RPED::MultiPedigree & get_multi_pedigree() const { return my_mp; }

    ///
    /// Returns the genotype model associated with this sample.
    const MLOCUS::genotype_model & get_gmodel() const { return my_mp.info().marker_info(my_config.get_marker()).gmodel(); }

    ///
    /// Returns the Configuration on the basis of which this Sampler was constructed.
    const Configuration & get_configuration() const { return my_config; }

    MPED::SexCode get_sex() const { return my_sex; }
  
  //@}

  /// @name Configuring the sample
  //@{

    void clear_error_count();

  //@}

  /// @name Sampling data
  //@{
  
    ///
    /// Returns a non-const pointer to the Table generated by sampling.
    TransmissionTablePtr get_table() { return my_table; }

    ///
    /// Returns a const pointer to the Table generated by sampling.
    const TransmissionTablePtr get_table() const { return my_table; }

    ///
    /// Returns the total number of pedigrees sampled.
    size_t getPedigreeCount() const;

    ///
    /// Returns the total number of families sampled.
    size_t getFamilyCount() const;

    ///
    /// Returns the total number of pairs sampled.
    size_t getPairCount() const;

    /// Returns the total number of sibs sampled.
    size_t getChildCount() const;

    ///
    /// Returns the total number of informative pedigrees sampled.
    size_t getInfPedigreeCount() const;

    ///
    /// Returns the total number of informative families sampled.
    size_t getInfFamilyCount()  const;

    ///
    /// Returns the total number of informative pairs sampled.
    size_t getInfPairCount() const;

    ///
    /// Returns the total number of informative sibs sampled.
    size_t getInfChildCount() const;

  //@}

  /// @name Error processing
  //@{

    ///
    /// Returns the error stream associated with this object.
    cerrorstream& get_errorstream();
    
    ///
    /// Returns the number of errors associated with this sample.
    size_t getErrorCount() const;

    ///
    /// Reports a mendelian inconsistency error.
    /// \param marker The index number of the marker in question
    /// \param parent1 The first parent
    /// \param parent2 The second parent
    /// \param child The child in question
    void generate_error(
            size_t         marker,
      const RPED::Member & parent1,
      const RPED::Member & parent2,
      const RPED::Member & child);

  //@}

protected:

  /// @name Internal sampling
  //@{
  
    bool sample_family(const RPED::Family& fam);

  //@}

  /// @name Affectedness
  //@{

    ///
    /// Indicates whether or not an individual is affected.
    /// \param ind The individual in question
    /// \param trait The index number of the trait in question
    /// \retval true The individual is affected
    /// \retval false The individual is not affected
    bool is_affected(const RPED::Member& ind, size_t trait) const;

    ///
    /// Indicates whether or not an individual is affected by the given child_trait().
    /// \param ind The individual in question
    /// \retval true The individual is affected
    /// \retval false The individual is not affected
    bool is_affected_child(const RPED::Member& child) const;

    ///
    /// Indicates whether or not an individual is affected by the given parent_trait().
    /// \param ind The individual in question
    /// \retval true The individual is affected
    /// \retval false The individual is not affected
    bool is_affected_parent(const RPED::Member& parent) const;

  //@}

  void filter_parents(
    const RPED::Member     & parent1, 
    const RPED::Member     & parent2,
          TransmissionList & xmit) const;
                           
  //=======================================================================
  //  DATA MEMBERS
  //=======================================================================

  const Configuration       & my_config;
  const RPED::MultiPedigree & my_mp;

  MPED::SexCode        my_sex;
  cerrorstream         my_errors;
  TransmissionTablePtr my_table;
  size_t               my_total_pedigrees;
  size_t               my_total_families;
  size_t               my_total_pairs;
  size_t               my_total_children;
  size_t               my_informative_pedigrees;
  size_t               my_informative_families;
  size_t               my_informative_pairs;
  size_t               my_informative_children;
  size_t               my_error_count;
  bool                 my_informative;
  
private:

  Sampler & operator= (const Sampler & other); // Disallowed
  
};

//==========================================
//  INLINE FUNCTIONS
//==========================================

inline       size_t                  Sampler::getErrorCount       () const { return my_error_count;           }  
inline       size_t                  Sampler::getPedigreeCount    () const { return my_total_pedigrees;       }
inline       size_t                  Sampler::getFamilyCount      () const { return my_total_families;        }
inline       size_t                  Sampler::getPairCount        () const { return my_total_pairs;           }
inline       size_t                  Sampler::getChildCount       () const { return my_total_children;        }
inline       size_t                  Sampler::getInfPedigreeCount () const { return my_informative_pedigrees; }
inline       size_t                  Sampler::getInfFamilyCount   () const { return my_informative_families;  }
inline       size_t                  Sampler::getInfPairCount     () const { return my_informative_pairs;     }
inline       size_t                  Sampler::getInfChildCount    () const { return my_informative_children;  }
inline       cerrorstream&           Sampler::get_errorstream     ()       { return my_errors;                   }
inline       void                    Sampler::clear_error_count   ()       { my_error_count = 0; }


} // End namespace TDTEX
} // End namespace SAGE

#endif
