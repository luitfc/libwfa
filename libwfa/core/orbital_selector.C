#include <libwfa/libwfa_exception.h>
#include "orbital_selector.h"


namespace libwfa {


void orbital_selector::select(bool as_occ, size_t i) {

    if (as_occ) {
#ifdef LIBWFA_DEBUG
        if (m_vir.is_selected(i)) {
            throw libwfa_exception("orbital_selector", "select(bool, size_t)",
                    __FILE__, __LINE__, "Selected as virtual.");
        }
#endif
        m_occ.select(i);
    }
    else {
#ifdef LIBWFA_DEBUG
        if (m_occ.is_selected(i)) {
            throw libwfa_exception("orbital_selector", "select(bool, size_t)",
                    __FILE__, __LINE__, "Selected as occupied.");
        }
#endif
        m_vir.select(i);
    }
}


void orbital_selector::select(bool as_occ,
    size_t i0, size_t i1, size_t inc, bool reverse) {

    if (reverse)
        for (size_t i = i0, j = i1 - 1; i < i1; i += inc, j -= inc) select(as_occ, j);
    else
        for (size_t i = i0; i < i1; i += inc) select(as_occ, i);
}


void orbital_selector::deselect(size_t i) {

    if (m_occ.is_selected(i))
        m_occ.deselect(i);
    else
        m_vir.deselect(i);
}


std::vector<size_t> orbital_selector::get_selected() const {

    std::vector<size_t> el;
    std::vector<size_t> elo(m_occ.get_selected());
    std::vector<size_t> elv(m_vir.get_selected());
    el.insert(el.end(), elo.begin(), elo.end());
    el.insert(el.end(), elv.begin(), elv.end());
    return el;
}


arma::Col<arma::uword> orbital_selector::get_selected_arma() const {

    arma::Col<arma::uword> el = 
        join_cols(m_occ.get_selected_arma(), m_vir.get_selected_arma());
    return el;
}


} // namespace libwfa

