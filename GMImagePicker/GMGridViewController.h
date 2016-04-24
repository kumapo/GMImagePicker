//
//  GMGridViewController.h
//  GMPhotoPicker
//
//  Created by Guillermo Muntaner Perelló on 19/09/14.
//  Copyright (c) 2014 Guillermo Muntaner Perelló. All rights reserved.
//


#import "GMImagePickerController.h"
@import UIKit;
@import Photos;

@protocol GMGridViewControllerDelegate <NSObject>

@property (nonatomic, assign) BOOL allowsMultipleSelection;
@property (nonatomic) double minimumInteritemSpacing;
@property (nonatomic) NSInteger colsInPortrait;
@property (nonatomic) NSInteger colsInLandscape;
@property (nonatomic) NSString * _Nullable customNavigationBarPrompt;
@property (nonatomic) UIStatusBarStyle pickerStatusBarStyle;
@property (nonatomic, strong) UIColor *pickerBackgroundColor;
@property (nonatomic) NSString * _Nullable  customDoneButtonTitle;
@property (nonatomic) NSString * _Nullable  customCancelButtonTitle;
@property (nonatomic, assign) BOOL autoDisableDoneButton;
@property (nonatomic, strong) NSArray<__kindof PHAsset *> *selectedAssets;
@property (nonatomic) BOOL useCustomFontForNavigationBar;
@property (nonatomic, strong) NSString * _Nonnull pickerFontName;
@property (nonatomic) CGFloat pickerFontHeaderSize;

@property(null_resettable, nonatomic,strong) UIView *view; //UIViewController
@property (nullable, nonatomic, strong) NSArray<__kindof UIBarButtonItem *> *toolbarItems;  //UINavigationController

- (void)selectAsset:(PHAsset * _Nonnull)asset;

@optional
- (BOOL)assetsViewController:(UIViewController *)viewController shouldEnableAsset:(PHAsset *)asset;
- (void)assetsViewController:(UIViewController *)viewController didSelectAsset:(PHAsset *)asset;

@end

@interface GMGridViewController : UICollectionViewController

@property (strong) PHFetchResult *assetsFetchResults;

-(id)initWithPicker:(GMImagePickerController *)picker;  //TODO: Remove
-(_Nonnull id)initWithDelegate:(_Nonnull id<GMGridViewControllerDelegate>)delegate;
@end