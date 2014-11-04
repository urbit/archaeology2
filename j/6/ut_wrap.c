/* j/6/wrap.c
**
** This file is in the public domain.
*/
#include "all.h"


  static u3_noun
  _cqfu_wrap(
                        u3_noun van,
                        u3_noun sut,
                        u3_noun yoz)
  {
    u3_noun p_sut, q_sut;

    if ( u3_no == u3du(sut) )  {
      return u3_cm_error("wrap-type");
    }
    else switch ( u3h(sut) ) {
      default: return u3_cm_error("wrap-type");

      case c3__core: u3_cx_cell(u3t(sut), &p_sut, &q_sut);
      {
        u3_noun pq_sut, qq_sut, rq_sut;

        if ( u3_no == u3_cr_trel(q_sut, &pq_sut, &qq_sut, &rq_sut) ) {
          return u3_cm_bail(c3__fail);
        }
        else if ( c3__gold != pq_sut ) {
          return u3_cm_error("wrap-gold");
        }
        else {
          return u3nt(c3__core,
                              u3k(p_sut),
                              u3nt(u3k(yoz),
                                           u3k(qq_sut),
                                           u3k(rq_sut)));
        }
      }
      case c3__fork: u3_cx_cell(u3t(sut), &p_sut, &q_sut);
      {
        return u3_cqf_fork
          (_cqfu_wrap(van, p_sut, yoz),
                  _cqfu_wrap(van, q_sut, yoz));
      }
      case c3__hold:
      {
        u3_noun fop = u3_cqfu_repo(van, sut);
        u3_noun pro = _cqfu_wrap(van, fop, yoz);

        u3z(fop);
        return pro;
      }
    }
  }

/* boilerplate
*/
  u3_noun
  u3_cwfu_wrap(
                       u3_noun cor)
  {
    u3_noun sut, yoz, van;

    if ( (u3_no == u3_cr_mean(cor, u3_cv_sam, &yoz, u3_cv_con, &van, 0)) ||
         (u3_none == (sut = u3_cr_at(u3_cv_sam, van))) )
    {
      return u3_cm_bail(c3__fail);
    } else {
      return _cqfu_wrap(van, sut, yoz);
    }
  }

  u3_noun
  u3_cqfu_wrap(u3_noun van,
                        u3_noun sut,
                        u3_noun yoz)
  {
    return _cqfu_wrap(van, sut, yoz);
  }
