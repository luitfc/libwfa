#include "density_type.h"

namespace libwfa {


const density_type density_type::state = density_type(0);
const density_type density_type::transition = density_type(1);
const density_type density_type::difference = density_type(2);
const density_type density_type::attach = density_type(3);
const density_type density_type::detach = density_type(4);
const density_type density_type::particle = density_type(5);
const density_type density_type::hole = density_type(6);


std::string density_type::convert() const {
    switch (m_type) {
    case 0: return "dens";
    case 1: return "trans";
    case 2: return "diff";
    case 3: return "attach";
    case 4: return "detach";
    case 5: return "elec";
    case 6: return "hole";
    default: return "unknown";
    }
}


std::ostream &operator<<(std::ostream &out, density_type type) {

    if (type == density_type::state)
        out << "State density matrix";
    else if (type == density_type::transition)
        out << "Transition density matrix";
    else if (type == density_type::difference)
        out << "Difference density matrix";
    else if (type == density_type::attach)
        out << "Attachment density matrix";
    else if (type == density_type::detach)
        out << "Detachment density matrix";
    else if (type == density_type::particle)
        out << "Electron density matrix";
    else if (type == density_type::hole)
        out << "Hole density matrix";
    else
        out << "Unknown density matrix";
    return out;
}


} // namespace libwfa

