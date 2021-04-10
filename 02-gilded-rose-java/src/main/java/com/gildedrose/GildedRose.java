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
        boolean isExpired = item.sellIn < 1;
        int degradeRate = determineDegradeRate(item, isExpired);
        boolean doesDegrade = !item.name.equals(AGED_BRIE) && !item.name.equals(BACKSTAGE_PASSES) && !item.name.equals(SULFURAS);
        boolean hasSellByDate = !item.name.equals(SULFURAS);

        if (doesDegrade) {
            adjustQuality(item, degradeRate);
        }

        if (item.name.equals(AGED_BRIE)) {
            int adjustment = isExpired ? 2 : 1;
            adjustQuality(item, adjustment);
        }

        if (item.name.equals(BACKSTAGE_PASSES)) {
            updateBackstagePassQuality(item, isExpired);
        }

        if (hasSellByDate) {
            item.sellIn = item.sellIn - 1;
        }
    }

    private void updateBackstagePassQuality(Item item, boolean isExpired) {
        adjustQuality(item, 1);
        if (item.sellIn < 11) {
            adjustQuality(item, 1);
        }

        if (item.sellIn < 6) {
            adjustQuality(item, 1);
        }
        if (isExpired) {
            item.quality = item.quality - item.quality;
        }
    }

    private int determineDegradeRate(Item item, boolean isExpired) {
        int baseDegradeRate = item.name.equals(CONJURED) ? -2 : -1;
        return isExpired ? baseDegradeRate * 2 : baseDegradeRate;
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