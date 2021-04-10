package com.gildedrose;

class GildedRose {

    public static final String AGED_BRIE = "Aged Brie";
    public static final String SULFURAS = "Sulfuras, Hand of Ragnaros";
    public static final String BACKSTAGE_PASSES = "Backstage passes to a TAFKAL80ETC concert";
    private Item[] items;

    public GildedRose(Item... items) {
        this.items = items;
    }

    public void updateQuality() {
        for (Item item : items) {
            updateItemQuality(item);
        }
    }

    private void updateItemQuality(Item item) {
        if (!item.name.equals(AGED_BRIE) && !item.name.equals(BACKSTAGE_PASSES)) {
            if (!item.name.equals(SULFURAS)) {
                adjustQuality(item, -1);
            }
        } else {
            adjustQuality(item, 1);

            if (item.name.equals(BACKSTAGE_PASSES)) {
                if (item.sellIn < 11) {
                    adjustQuality(item, 1);
                }

                if (item.sellIn < 6) {
                    adjustQuality(item, 1);
                }
            }
        }

        if (!item.name.equals(SULFURAS)) {
            item.sellIn = item.sellIn - 1;
        }

        if (item.sellIn < 0) {
            if (!item.name.equals(AGED_BRIE)) {
                if (!item.name.equals(BACKSTAGE_PASSES)) {
                    if (!item.name.equals(SULFURAS)) {
                        adjustQuality(item, -1);
                    }
                } else {
                    item.quality = item.quality - item.quality;
                }
            } else {
                adjustQuality(item, 1);
            }
        }
    }

    private void adjustQuality(Item item, int adjustment) {
        int newQuality = item.quality + adjustment;
        boolean inValidRange = newQuality <= 50 && newQuality >= 0;
        if (inValidRange) {
            item.quality = newQuality;
        }
    }

    public Item[] getItems() {
        return items;
    }
}