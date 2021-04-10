package com.gildedrose;

class GildedRose {

    public static final String AGED_BRIE = "Aged Brie";
    public static final String SULFURAS = "Sulfuras, Hand of Ragnaros";
    public static final String BACKSTAGE_PASSES = "Backstage passes to a TAFKAL80ETC concert";
    public static final String CONJURED = "Conjured Mana Cake";
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
        int degradeRate = item.name.equals(CONJURED) ? -2 : -1;
        boolean doesDegrade = !item.name.equals(AGED_BRIE) && !item.name.equals(BACKSTAGE_PASSES) && !item.name.equals(SULFURAS);

        if (doesDegrade) {
            adjustQuality(item, degradeRate);
        }

        if (item.name.equals(AGED_BRIE)) {
            adjustQuality(item, 1);
        }

        if (item.name.equals(BACKSTAGE_PASSES)) {
            adjustQuality(item, 1);
            if (item.sellIn < 11) {
                adjustQuality(item, 1);
            }

            if (item.sellIn < 6) {
                adjustQuality(item, 1);
            }
        }

        if (!item.name.equals(SULFURAS)) {
            item.sellIn = item.sellIn - 1;
        }

        if (item.sellIn < 0) {
            if (doesDegrade) {
                adjustQuality(item, degradeRate);
            }
            if (item.name.equals(AGED_BRIE)) {
                adjustQuality(item, 1);
            } else if (item.name.equals(BACKSTAGE_PASSES)) {
                item.quality = item.quality - item.quality;
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