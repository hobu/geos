#include "../../headers/indexBintree.h"
#include "../../headers/indexQuadtree.h"
#include "../../headers/util.h"

namespace geos {

double Root::origin=0.0;

Root::Root(){}
Root::~Root(){}

/**
* Insert an item into the tree this is the root of.
*/
void Root::insert(BinTreeInterval *itemInterval,void* item){
	int index=getSubnodeIndex(itemInterval,origin);
	// if index is -1, itemEnv must contain the origin.
	if (index==-1) {
		add(item);
		return;
	}
	/**
	* the item must be contained in one interval, so insert it into the
	* tree for that interval (which may not yet exist)
	*/
	BinTreeNode *node=subnode[index];
	/**
	*  If the subnode doesn't exist or this item is not contained in it,
	*  have to expand the tree upward to contain the item.
	*/
	if (node==NULL || !node->getInterval()->contains(itemInterval)) {
		BinTreeNode* largerNode=BinTreeNode::createExpanded(node,itemInterval);
		delete subnode[index];
		subnode[index]=largerNode;
	}
	/**
	* At this point we have a subnode which exists and must contain
	* contains the env for the item.  Insert the item into the tree.
	*/
	insertContained(subnode[index],itemInterval,item);
	//System.out.println("depth = " + root.depth() + " size = " + root.size());
}

/**
* insert an item which is known to be contained in the tree rooted at
* the given BinTreeNode.  Lower levels of the tree will be created
* if necessary to hold the item.
*/
void Root::insertContained(BinTreeNode *tree,BinTreeInterval *itemInterval,void* item) {
	Assert::isTrue(tree->getInterval()->contains(itemInterval));
	/**
	* Do NOT create a new node for zero-area intervals - this would lead
	* to infinite recursion. Instead, use a heuristic of simply returning
	* the smallest existing node containing the query
	*/
	bool isZeroArea=IntervalSize::isZeroWidth(itemInterval->getMin(),itemInterval->getMax());
	NodeBase *node;
	if (isZeroArea)
		node=tree->find(itemInterval);
	else
		node=tree->getNode(itemInterval);
	node->add(item);
}

/**
* The root node matches all searches
*/
bool Root::isSearchMatch(BinTreeInterval *interval){
	return true;
}
}

