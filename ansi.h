
namespace ansi {
    // RESET
    template < class CharT, class Traits >
    std::basic_ostream< CharT, Traits > & reset( std::basic_ostream< CharT, Traits > &os ) {
        return os << "\033[0m";
    }

    // FORGROUND NAMESPACE
    namespace foreground {      
        // BLACK
        template < class CharT, class Traits >
        std::basic_ostream< CharT, Traits > & black( std::basic_ostream< CharT, Traits > &os ) {
            return os << "\033[30m";
        }

        // RED
        template < class CharT, class Traits >
        std::basic_ostream< CharT, Traits > & red( std::basic_ostream< CharT, Traits > &os ) {
            return os << "\033[31m";
        }

        // GREEN
        template < class CharT, class Traits >
        std::basic_ostream< CharT, Traits > & green( std::basic_ostream< CharT, Traits > &os ) {
            return os << "\033[32m";
        }

        // YELLOW
        template < class CharT, class Traits >
        std::basic_ostream< CharT, Traits > & yellow( std::basic_ostream< CharT, Traits > &os ) {
            return os << "\033[33m";
        }

        // BLUE
        template < class CharT, class Traits >
        std::basic_ostream< CharT, Traits > & blue( std::basic_ostream< CharT, Traits > &os ) {
            return os << "\033[34m";
        }

        // MAGENTA
        template < class CharT, class Traits >
        std::basic_ostream< CharT, Traits > & magenta( std::basic_ostream< CharT, Traits > &os ) {
            return os << "\033[35m";
        }

        // CYAN
        template < class CharT, class Traits >
        std::basic_ostream< CharT, Traits > & cyan( std::basic_ostream< CharT, Traits > &os ) {
            return os << "\033[36m";
        }

        // WHITE
        template < class CharT, class Traits >
        std::basic_ostream< CharT, Traits > & white( std::basic_ostream< CharT, Traits > &os ) {
            return os << "\033[37m";
        }
    }
    
    // BACKGROUND NAMESPACE
    namespace background{
        // BLACK
        template < class CharT, class Traits >
        std::basic_ostream< CharT, Traits > & bg_black( std::basic_ostream< CharT, Traits > &os ) {
            return os << "\033[40m";
        }

        // RED
        template < class CharT, class Traits >
        std::basic_ostream< CharT, Traits > & bg_red( std::basic_ostream< CharT, Traits > &os ) {
            return os << "\033[41m";
        }

        // GREEN
        template < class CharT, class Traits >
        std::basic_ostream< CharT, Traits > & bg_green( std::basic_ostream< CharT, Traits > &os ) {
            return os << "\033[42m";
        }

        // YELLOW
        template < class CharT, class Traits >
        std::basic_ostream< CharT, Traits > & bg_yellow( std::basic_ostream< CharT, Traits > &os ) {
            return os << "\033[43m";
        }

        // BLUE
        template < class CharT, class Traits >
        std::basic_ostream< CharT, Traits > & bg_blue( std::basic_ostream< CharT, Traits > &os ) {
            return os << "\033[44m";
        }

        // MAGENTA
        template < class CharT, class Traits >
        std::basic_ostream< CharT, Traits > & bg_magenta( std::basic_ostream< CharT, Traits > &os ) {
            return os << "\033[45m";
        }

        // CYAN
        template < class CharT, class Traits >
        std::basic_ostream< CharT, Traits > & bg_cyan( std::basic_ostream< CharT, Traits > &os ) {
            return os << "\033[46m";
        }

        // WHITE
        template < class CharT, class Traits >
        std::basic_ostream< CharT, Traits > & bg_white( std::basic_ostream< CharT, Traits > &os ) {
            return os << "\033[47m";
        }
    }

    // BOLD FORGROUND NAMESPACE
    namespace boldground {
        // BLACK
        template < class CharT, class Traits >
        std::basic_ostream< CharT, Traits > & b_black( std::basic_ostream< CharT, Traits > &os ) {
            return os << "\033[1m\033[30m";
        }

        // RED
        template < class CharT, class Traits >
        std::basic_ostream< CharT, Traits > & b_red( std::basic_ostream< CharT, Traits > &os ) {
            return os << "\033[1m\033[31m";
        }

        // GREEN
        template < class CharT, class Traits >
        std::basic_ostream< CharT, Traits > & b_green( std::basic_ostream< CharT, Traits > &os ) {
            return os << "\033[1m\033[32m";
        }

        // YELLOW
        template < class CharT, class Traits >
        std::basic_ostream< CharT, Traits > & b_yellow( std::basic_ostream< CharT, Traits > &os ) {
            return os << "\033[1m\033[33m";
        }

        // BLUE
        template < class CharT, class Traits >
        std::basic_ostream< CharT, Traits > & b_blue( std::basic_ostream< CharT, Traits > &os ) {
            return os << "\033[1m\033[34m";
        }

        // MAGENTA
        template < class CharT, class Traits >
        std::basic_ostream< CharT, Traits > & b_magenta( std::basic_ostream< CharT, Traits > &os ) {
            return os << "\033[1m\033[35m";
        }

        // CYAN
        template < class CharT, class Traits >
        std::basic_ostream< CharT, Traits > & b_cyan( std::basic_ostream< CharT, Traits > &os ) {
            return os << "\033[1m\033[36m";
        }

        // WHITE
        template < class CharT, class Traits >
        std::basic_ostream< CharT, Traits > & b_white( std::basic_ostream< CharT, Traits > &os ) {
            return os << "\033[1m\033[37m";
        }
    }
}
