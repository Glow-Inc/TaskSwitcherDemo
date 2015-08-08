//
//  LTInfiniteScrollView.h
//  LTInfiniteScrollView
//
//  Created by ltebean on 14/11/21.
//  Copyright (c) 2014年 ltebean. All rights reserved.
//

#import <UIKit/UIKit.h>
typedef enum ScrollDirection {
    ScrollDirectionRight,
    ScrollDirectionLeft,
} ScrollDirection;

@protocol InfiniteScrollViewDelegate <NSObject>
- (void)updateView:(UIView *)view withProgress:(CGFloat)progress scrollDirection:(ScrollDirection)direction;
@end

@protocol InfiniteScrollViewDataSource <NSObject>
- (UIView *)viewAtIndex:(NSInteger)index reusingView:(UIView *)view;
- (NSInteger)numberOfViews;
- (NSInteger)numberOfVisibleViews;
@end

@interface InfiniteScrollView : UIView
@property (nonatomic, readonly) NSInteger currentIndex;
@property (nonatomic, weak) id<InfiniteScrollViewDataSource> dataSource;
@property (nonatomic, weak) id<InfiniteScrollViewDelegate> delegate;
@property (nonatomic) BOOL scrollEnabled;
@property (nonatomic) BOOL pagingEnabled;
@property (nonatomic) NSInteger maxScrollDistance;

- (void)reloadData;
- (void)scrollToIndex:(NSInteger)index animated:(BOOL)animated;
- (UIView *)viewAtIndex:(NSInteger)index;
- (NSArray *)allViews;
@end
