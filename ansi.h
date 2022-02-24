
namespace ansi {
    //RESET
    template < class CharT, class Traits >
    std::basic_ostream< CharT, Traits > & reset( std::basic_ostream< CharT, Traits > &os ) {
        return os << "\033[0m";
    }

    // BLACK
    template < class CharT, class Traits >
    std::basic_ostream< CharT, Traits > & black( std::basic_ostream< CharT, Traits > &os ) {
        return os << "\033[30m";
    }

    //RED
    template < class CharT, class Traits >
    std::basic_ostream< CharT, Traits > & red( std::basic_ostream< CharT, Traits > &os ) {
        return os << "\033[31m";
    }

    //GREEN
    template < class CharT, class Traits >
    std::basic_ostream< CharT, Traits > & green( std::basic_ostream< CharT, Traits > &os ) {
        return os << "\033[32m";
    }

    //YELLOW
    template < class CharT, class Traits >
    std::basic_ostream< CharT, Traits > & yellow( std::basic_ostream< CharT, Traits > &os ) {
        return os << "\033[33m";
    }

    //BLUE
    template < class CharT, class Traits >
    std::basic_ostream< CharT, Traits > & blue( std::basic_ostream< CharT, Traits > &os ) {
        return os << "\033[34m";
    }

    //MAGENTA
    template < class CharT, class Traits >
    std::basic_ostream< CharT, Traits > & magenta( std::basic_ostream< CharT, Traits > &os ) {
        return os << "\033[35m";
    }

    //CYAN
    template < class CharT, class Traits >
    std::basic_ostream< CharT, Traits > & cyan( std::basic_ostream< CharT, Traits > &os ) {
        return os << "\033[36m";
    }

    //WHITE
    template < class CharT, class Traits >
    std::basic_ostream< CharT, Traits > & white( std::basic_ostream< CharT, Traits > &os ) {
        return os << "\033[37m";
    }
}
