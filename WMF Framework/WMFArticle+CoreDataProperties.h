#import "WMFArticle+CoreDataClass.h"

@class ReadingList;

NS_ASSUME_NONNULL_BEGIN

@interface WMFArticle (CoreDataProperties)

+ (NSFetchRequest<WMFArticle *> *)fetchRequest;

@property (nullable, nonatomic, copy) NSString *key; // Key is a standardized version of the article URL generated by the wmf_databaseKey extension on NSURL. It's the desktop domain (for example, en.wikipedia.org instead of en.m.wikipedia.org) with /wiki/{{title}} as the path and no percent encoding. The scheme is https and there should be no fragment or query. The string is standardized with the `precomposedStringWithCanonicalMapping` method to prevent differences in encoding certain characters.

#pragma mark - User interaction
#pragma mark Reading Lists and Saving for Offline
@property (nullable, nonatomic, copy) NSDate *savedDate; // The date the user saved the article or nil if the article was never saved by the user
@property (nullable, nonatomic, retain) NSSet<ReadingList *> *readingLists;
@property (nullable, nonatomic, retain) NSSet<ReadingList *> *previewReadingLists;
@property (nullable, nonatomic, copy) NSNumber *errorCodeNumber; // error with article download - use error extension
@property (nonatomic) BOOL isDownloaded; // is fully downloaded for offline viewing
@property (nullable, nonatomic, copy) NSDate *downloadRetryDate; // The date when it's OK to retry the download
@property (nonatomic) int16_t downloadAttemptCount; // The number of attempts that have been made to download

@property (nonatomic) BOOL isConversionFromMobileViewNeeded;
#pragma mark Viewing
@property (nullable, nonatomic, copy) NSDate *viewedDate; // The date the user viewed the article in the article view or nil if the article was never viewed by the user
@property (nullable, nonatomic, copy) NSDate *viewedDateWithoutTime; // Viewed date without time for grouping by day in history
@property (nullable, nonatomic, copy) NSDate *lastModifiedDate; // Last date the article was modified

@property (nullable, nonatomic, copy) NSString *viewedFragment; // Last section fragment viewed by the user
@property (nonatomic) double viewedScrollPosition; // Last scroll position viewed by the user
@property (nonatomic) BOOL wasSignificantlyViewed; // Was viewed for a significant amount of time by the user
#pragma mark Other
@property (nonatomic) BOOL isExcludedFromFeed; // set to true if the user hid this article from the feed
@property (nullable, nonatomic, copy) NSDate *newsNotificationDate;
@property (nullable, nonatomic, copy) NSNumber *placesSortOrder;

#pragma mark - Metadata

@property (nullable, nonatomic, copy) NSString *displayTitle; // Don't use this property, use displayTitleHTML. It will set the plain text version to displayTitle.
@property (nullable, nonatomic, copy) NSString *imageURLString; // original image URL
@property (nonatomic, copy) NSNumber *imageHeight; // original image height
@property (nonatomic, copy) NSNumber *imageWidth; // original image width
@property (nullable, nonatomic, retain) NSDictionary *pageViews;
@property (nullable, nonatomic, copy) NSString *snippet;            // TODO: consider making naming consistent (probably use 'extract' instead of 'snippet' here and 'summary' elsewhere)
@property (nullable, nonatomic, copy) NSString *wikidataDescription;
@property (nullable, nonatomic, copy) NSString *wikidataID;
@property (nullable, nonatomic, copy) NSNumber *pageID; // The pageID from MediaWiki

#pragma mark - Coordinates and Geography
@property (nullable, nonatomic, copy) NSNumber *signedQuadKey; // representation of the latitude and longitude of the article. Use the `coordinate` extension to access this value
@property (nonatomic, copy) NSNumber *geoDimensionNumber; // geoDimension from search API
@property (nonatomic, copy) NSNumber *geoTypeNumber; // geoType from search API

#pragma mark - Deprecated
@property (nullable, nonatomic, copy) NSString *displayTitleHTMLString __attribute__((deprecated));  // This is used for storage of the displayTitleHTML but is "deprecated" in the sense that you shouldn't use this property, you should use displayTitleHTML which will set this and the display title
@property (nonatomic) double latitude;  //__deprecated; // Use coordinate instead (not using actual __deprecated tag due to inability to ignore the warning when these are used in Swift)
@property (nonatomic) double longitude; //__deprecated; // Use coordinate instead (not using actual __deprecated tag due to inability to ignore the warning when these are used in Swift)
@property (nullable, nonatomic, copy) NSNumber *ns __attribute__((deprecated)); // Use namespace extension instead
@property (nullable, nonatomic, copy) NSString *thumbnailURLString; // deprecated

@end

@interface WMFArticle (CoreDataGeneratedAccessors)

- (void)addReadingListsObject:(ReadingList *)value;
- (void)removeReadingListsObject:(ReadingList *)value;
- (void)addReadingLists:(NSSet<ReadingList *> *)values;
- (void)removeReadingLists:(NSSet<ReadingList *> *)values;

- (void)addPreviewReadingListsObject:(ReadingList *)value;
- (void)removePreviewReadingListsObject:(ReadingList *)value;
- (void)addPreviewReadingLists:(NSSet<ReadingList *> *)values;
- (void)removePreviewReadingLists:(NSSet<ReadingList *> *)values;

@end

NS_ASSUME_NONNULL_END
