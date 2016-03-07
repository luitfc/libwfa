#ifndef LIBWFA_MOLCAS_EXPORT_H5ORBS_H
#define LIBWFA_MOLCAS_EXPORT_H5ORBS_H

#include "H5Cpp.h"
#include <libwfa/export/export_molden_i.h>

namespace libwfa {

/** \brief Export to HDF5 file object for Molcas.
 
    This is based on the export_molden functionality of libwfa, since the
    required routines are similar.

    \ingroup libwfa_molcas
 **/
class molcas_export_h5orbs: public libwfa::export_molden_i {
private:
    H5::H5File m_file; //!< HDF5 file

public:
    /** \brief Constructor
        \param prefix Prefix of h5file (directory)
     **/
    molcas_export_h5orbs(H5::H5File &file) :
        m_file(file) { }

    /** \brief Virtual destructor
     **/
    virtual ~molcas_export_h5orbs() { }

    //! \name Implementation of libwfa::export_molden_i
    //@{
    virtual void perform(const std::string &name,
        const arma::mat &c, const arma::vec &e, size_t nocc);

    virtual void perform(const std::string &name,
        const arma::mat &c_a, const arma::vec &e_a, size_t nocc_a,
        const arma::mat &c_b, const arma::vec &e_b, size_t nocc_b);
    //@}
};


} // namespace libwfa

#endif // LIBWFA_MOLCAS_EXPORT_H5ORBS_H