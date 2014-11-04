/* j/2/slag.c
**
** This file is in the public domain.
*/
#include "all.h"


/* functions
*/
  u3_noun
  u3_cqb_slag(u3_atom a, u3_noun b)
  {
    if ( u3_ne(u3_co_is_cat(a)) ) {
      return u3_cm_bail(c3__fail);
    }
    else {
      c3_w len_w = a;

      while ( len_w ) {
        if ( u3_no == u3du(b) ) {
          return u3_nul;
        }
        b = u3t(b);
        len_w--;
      }
      return u3k(b);
    }
  }
  u3_noun
  u3_cwb_slag(u3_noun cor)
  {
    u3_noun a, b;

    if ( (u3_no == u3_cr_mean(cor, u3_cv_sam_2, &a, u3_cv_sam_3, &b, 0)) ||
         (u3_no == u3ud(a)) )
    {
      return u3_cm_bail(c3__exit);
    } else {
      return u3_cqb_slag(a, b);
    }
  }
