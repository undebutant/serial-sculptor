#include "BaseItem.h"

void BaseItem::draw(sf::RenderTarget &target) {
	target.draw(shape);
}

BaseItem::BaseItem()
{
}


BaseItem::~BaseItem()
{
}
