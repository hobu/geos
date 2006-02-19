/**********************************************************************
 * $Id$
 *
 * GEOS - Geometry Engine Open Source
 * http://geos.refractions.net
 *
 * Copyright (C) 2001-2002 Vivid Solutions Inc.
 *
 * This is free software; you can redistribute and/or modify it under
 * the terms of the GNU Lesser General Public Licence as published
 * by the Free Software Foundation. 
 * See the COPYING file for more information.
 *
 **********************************************************************
 * $Log$
 * Revision 1.5  2006/02/19 19:46:49  strk
 * Packages <-> namespaces mapping for most GEOS internal code (uncomplete, but working). Dir-level libs for index/ subdirs.
 *
 * Revision 1.4  2005/09/26 11:01:32  strk
 * Const correctness changes in LineMerger package, and a few speedups.
 *
 * Revision 1.3  2004/10/13 10:03:02  strk
 * Added missing linemerge and polygonize operation.
 * Bug fixes and leaks removal from the newly added modules and
 * planargraph (used by them).
 * Some comments and indentation changes.
 *
 * Revision 1.2  2004/07/02 13:28:28  strk
 * Fixed all #include lines to reflect headers layout change.
 * Added client application build tips in README.
 *
 * Revision 1.1  2004/04/07 06:55:50  ybychkov
 * "operation/linemerge" ported from JTS 1.4
 *
 *
 **********************************************************************/


#include <geos/opLinemerge.h>

namespace geos {
namespace operation { // geos.operation
namespace linemerge { // geos.operation.linemerge

/**
* Constructs a LineMergeEdge with vertices given by the specified LineString.
*/
LineMergeEdge::LineMergeEdge(const LineString *newLine):
	line(newLine)
{
	//line=newLine;
}

/**
 * Returns the LineString specifying the vertices of this edge.
 */
const LineString *
LineMergeEdge::getLine() const {
	return line;
}

} // namespace geos.operation.linemerge
} // namespace geos.operation
} // namespace geos
