package com.gildedrose;

import com.gildedrose.Item;

import static org.junit.Assert.assertEquals;

public class ItemTestHelper {

    public static void assertItemEquals(Item actual, Item expected) {
        assertEquals(expected.name, actual.name);
        assertEquals(expected.quality, actual.quality);
        assertEquals(expected.sellIn, actual.sellIn);
    }
}