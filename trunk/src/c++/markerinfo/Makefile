# Makefile for New Markerinfo Main Body
#
#  Authors: Kevin Jacobs (jacobs@darwin.cwru.edu)
#           Geoff Wedig  (wedig@darwin.cwru.edu)
#
#  History:   1.0   kbj  Initial implementation        Apr  5 1996
#             1.01  kbj  Refinements and confusion     Jun 10 1996
#             1.1   kbj  Finally got it right          Jul  1 1996
#             1.11  gcw  Relative Pair port            Jul 17 1996
#             1.2   gcw  Added Global.make, Rules.make Aug 19 1996
#             1.21  gcw  Written for RPped             Aug 20 1996
#             1.3   gcw  New Source handling           Jan 06 1997
#
#  Copyright (c) 1996  R.C. Elston
#
#  NOTE:  All S.A.G.E. programmers; this Makefile is a good example of how
#         to derive classes from LSF and build them.

#==========================================================================
# General target options                                                  |
#--------------------------------------------------------------------------
#
# -- These options apply to the entire Makefile, not any single target
#    o TARGET  is used for making a specific target
#    o TARGETS is the list of targets to be make by the recursive rule
#    o VERSION and TARPREFIX set parts of the archive name when the
#      tar rule is called.

  LSFROOT = ..
  SAGEROOT= ../..
  include $(SAGEROOT)/config/Global.make

  TARGET_NAME = Markerinfo Main Program
  TARGET      =
  TARGETS     = markerinfo$(EXE) 
  TESTTARGETS = markerinfo$(EXE)
  VERSION     = 1.0
  TESTS       = runall markerinfo

#==========================================================================
# Source/object file lists                                                |
#--------------------------------------------------------------------------

  HEADERS     = input.cpp markerinfo.cpp

  SRCS        = ${HEADERS:.h=.cpp}

  DEP_SRCS    = markerinfo.cpp

  OBJS        = ${SRCS:.cpp=.o}

    #======================================================================
    #   Target: markerinfo                                                |
    #----------------------------------------------------------------------

       markerinfo$(EXE).NAME     = "MARKERINFO"
       markerinfo$(EXE).INSTALL  = yes
       markerinfo$(EXE).TYPE     = C++
       markerinfo$(EXE).OBJS     = $(OBJS)
       markerinfo$(EXE).LDLIBS   = $(LIB_ALL)
       markerinfo$(EXE).CXXFLAGS =

include $(SAGEROOT)/config/Rules.make


# DO NOT DELETE THIS LINE -- make depend depends on it.


-include $(SRCS:%.cpp=$(BUILDDIR)/%.d)
-include $(DEP_SRCS:%.cpp=$(BUILDDIR)/%.d)

