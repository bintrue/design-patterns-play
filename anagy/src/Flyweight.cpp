/*
 * Flyweight ala Attish.
 *
 * Name origin:
 *   boxing weight class.
 *
 * Features:
 * - an object that minimizes memory use by sharing as much data as possible with other similar objects,
 * - used large number of objects,
 * - shared parts of the objects must be put in external data structures,
 * - flyweight objects do not store them, just get them temporarily when it is needed.
 * - it is an alternative for hash consing. ( http://en.wikipedia.org/wiki/Hash_consing )
 * 
 * Example:
 * - 'A classic example usage of the flyweight pattern is the data structures for graphical representation of characters in a word processor. It might be desirable to have, for each character in a document, a glyph object containing its font outline, font metrics, and other formatting data, but this would amount to hundreds or thousands of bytes for each character. Instead, for every character there might be a reference to a flyweight glyph object shared by every instance of the same character in the document; only the position of each character (in the document and/or the page) would need to be stored internally.' ( cited from http://en.wikipedia.org/wiki/Flyweight_pattern )
 * 
 * Source code:
 *
 * Coming...
 *
 */
