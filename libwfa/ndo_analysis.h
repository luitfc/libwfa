#ifndef LIBWFA_NDO_ANALYSIS_H
#define LIBWFA_NDO_ANALYSIS_H

#include <utility>
#include "ev_printer_i.h"
#include "export_densities_i.h"
#include "export_orbitals_i.h"

namespace libwfa {


/** \brief Perform complete NDO analysis of a transition density matrix

     \ingroup libwfa
 **/
class ndo_analysis {
public:
    typedef std::pair<ab_matrix, ab_matrix> ab_matrix_pair;

private:
    const arma::Mat<double> &m_s; //!< Overlap matrix
    const ab_matrix &m_c; //!< MO coefficients

public:
    /** \brief Constructor
        \param s Overlap matrix
        \param c Orbital coefficient matrix for transform in orthogonal basis
     **/
    ndo_analysis(const arma::Mat<double> &s, const ab_matrix &c) :
        m_s(s), m_c(c) { }

    /** \brief Perform NDO analysis
        \param[in] ddm Difference density matrix
        \param[out] ad Attachment / detachment densities (first attach)
        \param[out] pr_o Printer of NTOs
        \param[out] pr_e Printer of NTO occupation numbers
     **/
    void perform(const ab_matrix &ddm, ab_matrix_pair &ad,
        export_orbitals_i &pr_o, ev_printer_i &pr_e) const;

    /** \brief Perform NDO analysis
        \param[in] ddm Difference density matrix
        \param[out] pr_d Printer of density matrices
        \param[out] pr_o Printer of NTOs
        \param[out] pr_e Printer of NTO occupation numbers
     **/
    void perform(const ab_matrix &ddm, export_densities_i &pr_d,
        export_orbitals_i &pr_o, ev_printer_i &pr_e) const;
};

} // namespace libwfa

#endif
