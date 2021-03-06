/*
 * Copyright (c) 2006-2008 Peter Simons <simons@cryp.to>
 *
 * This software is provided 'as-is', without any express or
 * implied warranty. In no event will the authors be held liable
 * for any damages arising from the use of this software.
 *
 * Copying and distribution of this file, with or without
 * modification, are permitted in any medium without royalty
 * provided the copyright notice and this notice are preserved.
 */

#ifndef RFC2822_ATOM_HPP_INCLUDED
#define RFC2822_ATOM_HPP_INCLUDED

#include "base.hpp"

namespace rfc2822
{
  struct atom_parser : public spirit::grammar<atom_parser>
  {
    atom_parser() { }

    template<typename scannerT>
    struct definition
    {
      spirit::rule<scannerT>    atom;

      definition(atom_parser const &)
      {
        using namespace spirit;
        atom =
          lexeme_d
          [
            +( anychar_p - ( chset_p(" \x7F()<>@,;:\\\".[]")
                           | range_p('\x00','\x1F')
                           )
             )
          ];

        BOOST_SPIRIT_DEBUG_NODE(atom);
      }

      spirit::rule<scannerT> const & start() const { return atom; }
    };
  };

} // rfc2822

#endif // RFC2822_ATOM_HPP_INCLUDED
