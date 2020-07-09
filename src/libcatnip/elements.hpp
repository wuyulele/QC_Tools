#include <algorithm>
#include <cctype>
#include <map>
#include <string>

namespace catnip {

  enum class Element {
    Ac,
    Al,
    Am,
    Sb,
    Ar,
    As,
    At,
    Ba,
    Bk,
    Be,
    Bi,
    Bh,
    B,
    Br,
    Cd,
    Ca,
    Cf,
    C,
    Ce,
    Cs,
    Cl,
    Cr,
    Co,
    Cu,
    Cm,
    Ds,
    Db,
    Dy,
    Es,
    Er,
    Eu,
    Fm,
    F,
    Fr,
    Gd,
    Ga,
    Ge,
    Au,
    Hf,
    Hs,
    He,
    Ho,
    H,
    In,
    I,
    Ir,
    Fe,
    Kr,
    La,
    Lr,
    Pb,
    Li,
    Lu,
    Mg,
    Mn,
    Mt,
    Md,
    Hg,
    Mo,
    Nd,
    Ne,
    Np,
    Ni,
    Nb,
    N,
    No,
    Uuo,
    Os,
    O,
    Pd,
    P,
    Pt,
    Pu,
    Po,
    K,
    Pr,
    Pm,
    Pa,
    Ra,
    Rn,
    Re,
    Rh,
    Rg,
    Rb,
    Ru,
    Rf,
    Sm,
    Sc,
    Sg,
    Se,
    Si,
    Ag,
    Na,
    Sr,
    S,
    Ta,
    Tc,
    Te,
    Tb,
    Tl,
    Th,
    Tm,
    Sn,
    Ti,
    W,
    Uub,
    Uuh,
    Uup,
    Uuq,
    Uus,
    Uut,
    U,
    V,
    Xe,
    Yb,
    Y,
    Zn,
    Zr,
    Unknown
  };

  /**
   * @brief For manipulating Elements
   *
   * Converts string to enum class type
   */
  class Elements {

    private:
      void to_lower_(std::string & data) const noexcept {
        std::transform(data.begin(), data.end(), data.begin(),
          [](unsigned char c){ return std::tolower(c); });
      }
    public: 

      /**
       * @brief Case insensitive get Element enum
       *
       * @param element_name
       *
       * @return 
       */
      Element getElement(std::string element_name) const noexcept {
        to_lower_(element_name);
        if( elements_.count(element_name)) {
          return elements_.at(element_name);
        }
        if( elementssym_.count(element_name)) {
          return elementssym_.at(element_name);
        }
        return Element::Unknown;
      }

    private:
      std::map<std::string, Element> elements_ = {
        {"actinium",     Element::Ac},
        {"aluminum",     Element::Al},
        {"americium",    Element::Am},
        {"antimony",     Element::Sb},
        {"argon",        Element::Ar},
        {"arsenic",      Element::As},
        {"astatine",     Element::At},
        {"barium",       Element::Ba},
        {"berkelium",    Element::Bk},
        {"beryllium",    Element::Be},
        {"bismuth",      Element::Bi},
        {"bohrium",      Element::Bh},
        {"boron",        Element::B},
        {"bromine",      Element::Br},
        {"cadmium",      Element::Cd},
        {"calcium",      Element::Ca},
        {"californium",  Element::Cf},
        {"carbon",       Element::C},
        {"cerium",       Element::Ce},
        {"cesium",       Element::Cs},
        {"chlorine",     Element::Cl},
        {"chromium",     Element::Cr},
        {"cobalt",       Element::Co},
        {"copper",       Element::Cu},
        {"curium",       Element::Cm},
        {"darmstadtium", Element::Ds},
        {"dubnium",      Element::Db},
        {"dysprosium",   Element::Dy},
        {"einsteinium",  Element::Es},
        {"erbium",       Element::Er},
        {"europium",     Element::Eu},
        {"fermium",      Element::Fm},
        {"fluorine",     Element::F},
        {"francium",     Element::Fr},
        {"gadolinium",   Element::Gd},
        {"gallium",      Element::Ga},
        {"germanium",    Element::Ge},
        {"gold",         Element::Au},
        {"hafnium",      Element::Hf},
        {"hassium",      Element::Hs},
        {"helium",       Element::He},
        {"holmium",      Element::Ho},
        {"hydrogen",     Element::H},
        {"indium",       Element::In},
        {"iodine",       Element::I},
        {"iridium",      Element::Ir},
        {"iron",         Element::Fe},
        {"krypton",      Element::Kr},
        {"lanthanum",    Element::La},
        {"lawrencium",   Element::Lr},
        {"lead",         Element::Pb},
        {"lithium",      Element::Li},
        {"lutetium",     Element::Lu},
        {"magnesium",    Element::Mg},
        {"manganese",    Element::Mn},
        {"meitnerium",   Element::Mt},
        {"mendelevium",  Element::Md},
        {"mercury",      Element::Hg},
        {"molybdenum",   Element::Mo},
        {"neodymium",    Element::Nd},
        {"neon",         Element::Ne},
        {"neptunium",    Element::Np},
        {"nickel",       Element::Ni},
        {"niobium",      Element::Nb},
        {"nitrogen",     Element::N},
        {"nobelium",     Element::No},
        {"oganesson",    Element::Uuo},
        {"osmium",       Element::Os},
        {"oxygen",       Element::O},
        {"palladium",    Element::Pd},
        {"phosphorus",   Element::P},
        {"platinum",     Element::Pt},
        {"plutonium",    Element::Pu},
        {"polonium",     Element::Po},
        {"potassium",    Element::K},
        {"praseodymium", Element::Pr},
        {"promethium",   Element::Pm},
        {"protactinium", Element::Pa},
        {"radium",       Element::Ra},
        {"radon",        Element::Rn},
        {"rhenium",      Element::Re},
        {"rhodium",      Element::Rh},
        {"roentgenium",  Element::Rg},
        {"rubidium",     Element::Rb},
        {"ruthenium",    Element::Ru},
        {"rutherfordium",Element::Rf},
        {"samarium",     Element::Sm},
        {"scandium",     Element::Sc},
        {"seaborgium",   Element::Sg},
        {"selenium",     Element::Se},
        {"silicon",      Element::Si},
        {"silver",       Element::Ag},
        {"sodium",       Element::Na},
        {"strontium",    Element::Sr},
        {"sulfur",       Element::S},
        {"tantalum",     Element::Ta},
        {"technetium",   Element::Tc},
        {"tellurium",    Element::Te},
        {"terbium",      Element::Tb},
        {"thallium",     Element::Tl},
        {"thorium",      Element::Th},
        {"thulium",      Element::Tm},
        {"tin",          Element::Sn},
        {"titanium",     Element::Ti},
        {"tungsten",     Element::W},
        {"ununbium",     Element::Uub},
        {"ununhexium",   Element::Uuh},
        {"ununpentium",  Element::Uup},
        {"ununquadium",  Element::Uuq},
        {"ununseptium",  Element::Uus},
        {"ununtrium",    Element::Uut},
        {"uranium",      Element::U},
        {"vanadium",     Element::V},
        {"xenon",        Element::Xe},
        {"ytterbium",    Element::Yb},
        {"yttrium",      Element::Y},
        {"zinc",         Element::Zn},
        {"zirconium",    Element::Zr}};

      std::map<std::string, Element> elementssym_ = {
        {"ac",    Element::Ac},
        {"al",    Element::Al},
        {"am",    Element::Am},
        {"sb",    Element::Sb},
        {"ar",    Element::Ar},
        {"as",    Element::As},
        {"at",    Element::At},
        {"ba",    Element::Ba},
        {"bk",    Element::Bk},
        {"be",    Element::Be},
        {"bi",    Element::Bi},
        {"bh",    Element::Bh},
        {"b",     Element::B},
        {"br",    Element::Br},
        {"cd",    Element::Cd},
        {"ca",    Element::Ca},
        {"cf",    Element::Cf},
        {"c",     Element::C},
        {"ce",    Element::Ce},
        {"cs",    Element::Cs},
        {"cl",    Element::Cl},
        {"cr",    Element::Cr},
        {"co",    Element::Co},
        {"cu",    Element::Cu},
        {"cm",    Element::Cm},
        {"ds",    Element::Ds},
        {"db",    Element::Db},
        {"dy",    Element::Dy},
        {"es",    Element::Es},
        {"er",    Element::Er},
        {"eu",    Element::Eu},
        {"fm",    Element::Fm},
        {"f",     Element::F},
        {"fr",    Element::Fr},
        {"gd",    Element::Gd},
        {"ga",    Element::Ga},
        {"ge",    Element::Ge},
        {"au",    Element::Au},
        {"hf",    Element::Hf},
        {"hs",    Element::Hs},
        {"he",    Element::He},
        {"ho",    Element::Ho},
        {"h",     Element::H},
        {"in",    Element::In},
        {"i",     Element::I},
        {"ir",    Element::Ir},
        {"fe",    Element::Fe},
        {"kr",    Element::Kr},
        {"la",    Element::La},
        {"lr",    Element::Lr},
        {"pb",    Element::Pb},
        {"li",    Element::Li},
        {"lu",    Element::Lu},
        {"mg",    Element::Mg},
        {"mn",    Element::Mn},
        {"mt",    Element::Mt},
        {"md",    Element::Md},
        {"hg",    Element::Hg},
        {"mo",    Element::Mo},
        {"nd",    Element::Nd},
        {"ne",    Element::Ne},
        {"np",    Element::Np},
        {"ni",    Element::Ni},
        {"nb",    Element::Nb},
        {"n",     Element::N},
        {"no",    Element::No},
        {"uuo",   Element::Uuo},
        {"os",    Element::Os},
        {"o",     Element::O},
        {"pd",    Element::Pd},
        {"p",     Element::P},
        {"pt",    Element::Pt},
        {"pu",    Element::Pu},
        {"po",    Element::Po},
        {"k",     Element::K},
        {"pr",    Element::Pr},
        {"pm",    Element::Pm},
        {"pa",    Element::Pa},
        {"ra",    Element::Ra},
        {"rn",    Element::Rn},
        {"re",    Element::Re},
        {"rh",    Element::Rh},
        {"rg",    Element::Rg},
        {"rb",    Element::Rb},
        {"ru",    Element::Ru},
        {"rf",    Element::Rf},
        {"sm",    Element::Sm},
        {"sc",    Element::Sc},
        {"sg",    Element::Sg},
        {"se",    Element::Se},
        {"si",    Element::Si},
        {"ag",    Element::Ag},
        {"na",    Element::Na},
        {"sr",    Element::Sr},
        {"s",     Element::S},
        {"ta",    Element::Ta},
        {"tc",    Element::Tc},
        {"te",    Element::Te},
        {"tb",    Element::Tb},
        {"tl",    Element::Tl},
        {"th",    Element::Th},
        {"tm",    Element::Tm},
        {"sn",    Element::Sn},
        {"ti",    Element::Ti},
        {"w",     Element::W},
        {"uub",   Element::Uub},
        {"uuh",   Element::Uuh},
        {"uup",   Element::Uup},
        {"uuq",   Element::Uuq},
        {"uus",   Element::Uus},
        {"uut",   Element::Uut},
        {"u",     Element::U},
        {"v",     Element::V},
        {"xe",    Element::Xe},
        {"yb",    Element::Yb},
        {"y",     Element::Y},
        {"zn",    Element::Zn},
        {"zr",    Element::Zr}};

  };

}

