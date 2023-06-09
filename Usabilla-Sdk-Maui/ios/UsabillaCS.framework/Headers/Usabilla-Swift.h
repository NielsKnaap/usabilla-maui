#if 0
#elif defined(__arm64__) && __arm64__
// Generated by Apple Swift version 5.7.2 effective-4.1.50 (swiftlang-5.7.2.135.5 clang-1400.0.29.51)
#ifndef USABILLACS_SWIFT_H
#define USABILLACS_SWIFT_H
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wgcc-compat"

#if !defined(__has_include)
# define __has_include(x) 0
#endif
#if !defined(__has_attribute)
# define __has_attribute(x) 0
#endif
#if !defined(__has_feature)
# define __has_feature(x) 0
#endif
#if !defined(__has_warning)
# define __has_warning(x) 0
#endif

#if __has_include(<swift/objc-prologue.h>)
# include <swift/objc-prologue.h>
#endif

#pragma clang diagnostic ignored "-Wduplicate-method-match"
#pragma clang diagnostic ignored "-Wauto-import"
#if defined(__OBJC__)
#include <Foundation/Foundation.h>
#endif
#if defined(__cplusplus)
#include <cstdint>
#include <cstddef>
#include <cstdbool>
#else
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#endif

#if !defined(SWIFT_TYPEDEFS)
# define SWIFT_TYPEDEFS 1
# if __has_include(<uchar.h>)
#  include <uchar.h>
# elif !defined(__cplusplus)
typedef uint_least16_t char16_t;
typedef uint_least32_t char32_t;
# endif
typedef float swift_float2  __attribute__((__ext_vector_type__(2)));
typedef float swift_float3  __attribute__((__ext_vector_type__(3)));
typedef float swift_float4  __attribute__((__ext_vector_type__(4)));
typedef double swift_double2  __attribute__((__ext_vector_type__(2)));
typedef double swift_double3  __attribute__((__ext_vector_type__(3)));
typedef double swift_double4  __attribute__((__ext_vector_type__(4)));
typedef int swift_int2  __attribute__((__ext_vector_type__(2)));
typedef int swift_int3  __attribute__((__ext_vector_type__(3)));
typedef int swift_int4  __attribute__((__ext_vector_type__(4)));
typedef unsigned int swift_uint2  __attribute__((__ext_vector_type__(2)));
typedef unsigned int swift_uint3  __attribute__((__ext_vector_type__(3)));
typedef unsigned int swift_uint4  __attribute__((__ext_vector_type__(4)));
#endif

#if !defined(SWIFT_PASTE)
# define SWIFT_PASTE_HELPER(x, y) x##y
# define SWIFT_PASTE(x, y) SWIFT_PASTE_HELPER(x, y)
#endif
#if !defined(SWIFT_METATYPE)
# define SWIFT_METATYPE(X) Class
#endif
#if !defined(SWIFT_CLASS_PROPERTY)
# if __has_feature(objc_class_property)
#  define SWIFT_CLASS_PROPERTY(...) __VA_ARGS__
# else
#  define SWIFT_CLASS_PROPERTY(...)
# endif
#endif

#if __has_attribute(objc_runtime_name)
# define SWIFT_RUNTIME_NAME(X) __attribute__((objc_runtime_name(X)))
#else
# define SWIFT_RUNTIME_NAME(X)
#endif
#if __has_attribute(swift_name)
# define SWIFT_COMPILE_NAME(X) __attribute__((swift_name(X)))
#else
# define SWIFT_COMPILE_NAME(X)
#endif
#if __has_attribute(objc_method_family)
# define SWIFT_METHOD_FAMILY(X) __attribute__((objc_method_family(X)))
#else
# define SWIFT_METHOD_FAMILY(X)
#endif
#if __has_attribute(noescape)
# define SWIFT_NOESCAPE __attribute__((noescape))
#else
# define SWIFT_NOESCAPE
#endif
#if __has_attribute(ns_consumed)
# define SWIFT_RELEASES_ARGUMENT __attribute__((ns_consumed))
#else
# define SWIFT_RELEASES_ARGUMENT
#endif
#if __has_attribute(warn_unused_result)
# define SWIFT_WARN_UNUSED_RESULT __attribute__((warn_unused_result))
#else
# define SWIFT_WARN_UNUSED_RESULT
#endif
#if __has_attribute(noreturn)
# define SWIFT_NORETURN __attribute__((noreturn))
#else
# define SWIFT_NORETURN
#endif
#if !defined(SWIFT_CLASS_EXTRA)
# define SWIFT_CLASS_EXTRA
#endif
#if !defined(SWIFT_PROTOCOL_EXTRA)
# define SWIFT_PROTOCOL_EXTRA
#endif
#if !defined(SWIFT_ENUM_EXTRA)
# define SWIFT_ENUM_EXTRA
#endif
#if !defined(SWIFT_CLASS)
# if __has_attribute(objc_subclassing_restricted)
#  define SWIFT_CLASS(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) __attribute__((objc_subclassing_restricted)) SWIFT_CLASS_EXTRA
#  define SWIFT_CLASS_NAMED(SWIFT_NAME) __attribute__((objc_subclassing_restricted)) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
# else
#  define SWIFT_CLASS(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
#  define SWIFT_CLASS_NAMED(SWIFT_NAME) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
# endif
#endif
#if !defined(SWIFT_RESILIENT_CLASS)
# if __has_attribute(objc_class_stub)
#  define SWIFT_RESILIENT_CLASS(SWIFT_NAME) SWIFT_CLASS(SWIFT_NAME) __attribute__((objc_class_stub))
#  define SWIFT_RESILIENT_CLASS_NAMED(SWIFT_NAME) __attribute__((objc_class_stub)) SWIFT_CLASS_NAMED(SWIFT_NAME)
# else
#  define SWIFT_RESILIENT_CLASS(SWIFT_NAME) SWIFT_CLASS(SWIFT_NAME)
#  define SWIFT_RESILIENT_CLASS_NAMED(SWIFT_NAME) SWIFT_CLASS_NAMED(SWIFT_NAME)
# endif
#endif

#if !defined(SWIFT_PROTOCOL)
# define SWIFT_PROTOCOL(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) SWIFT_PROTOCOL_EXTRA
# define SWIFT_PROTOCOL_NAMED(SWIFT_NAME) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_PROTOCOL_EXTRA
#endif

#if !defined(SWIFT_EXTENSION)
# define SWIFT_EXTENSION(M) SWIFT_PASTE(M##_Swift_, __LINE__)
#endif

#if !defined(OBJC_DESIGNATED_INITIALIZER)
# if __has_attribute(objc_designated_initializer)
#  define OBJC_DESIGNATED_INITIALIZER __attribute__((objc_designated_initializer))
# else
#  define OBJC_DESIGNATED_INITIALIZER
# endif
#endif
#if !defined(SWIFT_ENUM_ATTR)
# if defined(__has_attribute) && __has_attribute(enum_extensibility)
#  define SWIFT_ENUM_ATTR(_extensibility) __attribute__((enum_extensibility(_extensibility)))
# else
#  define SWIFT_ENUM_ATTR(_extensibility)
# endif
#endif
#if !defined(SWIFT_ENUM)
# define SWIFT_ENUM(_type, _name, _extensibility) enum _name : _type _name; enum SWIFT_ENUM_ATTR(_extensibility) SWIFT_ENUM_EXTRA _name : _type
# if __has_feature(generalized_swift_name)
#  define SWIFT_ENUM_NAMED(_type, _name, SWIFT_NAME, _extensibility) enum _name : _type _name SWIFT_COMPILE_NAME(SWIFT_NAME); enum SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_ENUM_ATTR(_extensibility) SWIFT_ENUM_EXTRA _name : _type
# else
#  define SWIFT_ENUM_NAMED(_type, _name, SWIFT_NAME, _extensibility) SWIFT_ENUM(_type, _name, _extensibility)
# endif
#endif
#if !defined(SWIFT_UNAVAILABLE)
# define SWIFT_UNAVAILABLE __attribute__((unavailable))
#endif
#if !defined(SWIFT_UNAVAILABLE_MSG)
# define SWIFT_UNAVAILABLE_MSG(msg) __attribute__((unavailable(msg)))
#endif
#if !defined(SWIFT_AVAILABILITY)
# define SWIFT_AVAILABILITY(plat, ...) __attribute__((availability(plat, __VA_ARGS__)))
#endif
#if !defined(SWIFT_WEAK_IMPORT)
# define SWIFT_WEAK_IMPORT __attribute__((weak_import))
#endif
#if !defined(SWIFT_DEPRECATED)
# define SWIFT_DEPRECATED __attribute__((deprecated))
#endif
#if !defined(SWIFT_DEPRECATED_MSG)
# define SWIFT_DEPRECATED_MSG(...) __attribute__((deprecated(__VA_ARGS__)))
#endif
#if __has_feature(attribute_diagnose_if_objc)
# define SWIFT_DEPRECATED_OBJC(Msg) __attribute__((diagnose_if(1, Msg, "warning")))
#else
# define SWIFT_DEPRECATED_OBJC(Msg) SWIFT_DEPRECATED_MSG(Msg)
#endif
#if defined(__OBJC__)
#if !defined(IBSegueAction)
# define IBSegueAction
#endif
#endif
#if !defined(SWIFT_EXTERN)
# if defined(__cplusplus)
#  define SWIFT_EXTERN extern "C"
# else
#  define SWIFT_EXTERN extern
# endif
#endif
#if !defined(SWIFT_CALL)
# define SWIFT_CALL __attribute__((swiftcall))
#endif
#if defined(__cplusplus)
#if !defined(SWIFT_NOEXCEPT)
# define SWIFT_NOEXCEPT noexcept
#endif
#else
#if !defined(SWIFT_NOEXCEPT)
# define SWIFT_NOEXCEPT 
#endif
#endif
#if defined(__cplusplus)
#if !defined(SWIFT_CXX_INT_DEFINED)
#define SWIFT_CXX_INT_DEFINED
namespace swift {
using Int = ptrdiff_t;
using UInt = size_t;
}
#endif
#endif
#if defined(__OBJC__)
#if __has_feature(modules)
#if __has_warning("-Watimport-in-framework-header")
#pragma clang diagnostic ignored "-Watimport-in-framework-header"
#endif
@import Foundation;
@import ObjectiveC;
@import UIKit;
#endif

#endif
#pragma clang diagnostic ignored "-Wproperty-attribute-mismatch"
#pragma clang diagnostic ignored "-Wduplicate-method-arg"
#if __has_warning("-Wpragma-clang-attribute")
# pragma clang diagnostic ignored "-Wpragma-clang-attribute"
#endif
#pragma clang diagnostic ignored "-Wunknown-pragmas"
#pragma clang diagnostic ignored "-Wnullability"
#pragma clang diagnostic ignored "-Wdollar-in-identifier-extension"

#if __has_attribute(external_source_symbol)
# pragma push_macro("any")
# undef any
# pragma clang attribute push(__attribute__((external_source_symbol(language="Swift", defined_in="UsabillaCS",generated_declaration))), apply_to=any(function,enum,objc_interface,objc_category,objc_protocol))
# pragma pop_macro("any")
#endif

#if defined(__OBJC__)

@class NSString;

SWIFT_CLASS_NAMED("FeedbackResult")
@interface FeedbackResult : NSObject
@property (nonatomic, strong) NSString * _Nullable rating;
@property (nonatomic, strong) NSString * _Nullable abandonedPageIndex;
@property (nonatomic, readonly) BOOL sent;
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_DEPRECATED_MSG("-init is unavailable");
@end




SWIFT_CLASS_NAMED("UBError")
@interface UBError : NSObject
@property (nonatomic, strong) NSString * _Nullable errorDescription;
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_DEPRECATED_MSG("-init is unavailable");
@end














@protocol UsabillaDelegate;
@class UIImage;
@class UIView;

SWIFT_CLASS_NAMED("UsabillaCS")
@interface Usabilla : NSObject
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, copy) NSDictionary<NSString *, NSString *> * _Nonnull customVariables;)
+ (NSDictionary<NSString *, NSString *> * _Nonnull)customVariables SWIFT_WARN_UNUSED_RESULT;
+ (void)setCustomVariables:(NSDictionary<NSString *, NSString *> * _Nonnull)newValue;
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, readonly, copy) NSArray<NSString *> * _Nonnull defaultDataMasks;)
+ (NSArray<NSString *> * _Nonnull)defaultDataMasks SWIFT_WARN_UNUSED_RESULT;
SWIFT_CLASS_PROPERTY(@property (nonatomic, class) UIInterfaceOrientationMask orientation;)
+ (UIInterfaceOrientationMask)orientation SWIFT_WARN_UNUSED_RESULT;
+ (void)setOrientation:(UIInterfaceOrientationMask)newValue;
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, copy) NSString * _Nonnull localizedStringFile;)
+ (NSString * _Nonnull)localizedStringFile SWIFT_WARN_UNUSED_RESULT;
+ (void)setLocalizedStringFile:(NSString * _Nonnull)newValue;
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, strong) id <UsabillaDelegate> _Nullable delegate;)
+ (id <UsabillaDelegate> _Nullable)delegate SWIFT_WARN_UNUSED_RESULT;
+ (void)setDelegate:(id <UsabillaDelegate> _Nullable)newValue;
SWIFT_CLASS_PROPERTY(@property (nonatomic, class) BOOL canDisplayCampaigns;)
+ (BOOL)canDisplayCampaigns SWIFT_WARN_UNUSED_RESULT;
+ (void)setCanDisplayCampaigns:(BOOL)newValue;
/// A Boolean value that determines whether the SDK should display logs.
SWIFT_CLASS_PROPERTY(@property (nonatomic, class) BOOL debugEnabled;)
+ (BOOL)debugEnabled SWIFT_WARN_UNUSED_RESULT;
+ (void)setDebugEnabled:(BOOL)newValue;
/// A Boolean value that determines whether the SDK should send telemetry data.
SWIFT_CLASS_PROPERTY(@property (nonatomic, class) BOOL submitTelemetryData;)
+ (BOOL)submitTelemetryData SWIFT_WARN_UNUSED_RESULT;
+ (void)setSubmitTelemetryData:(BOOL)newValue;
/// A Boolean value that determines whether the SDK powered by logo clickable.
SWIFT_CLASS_PROPERTY(@property (nonatomic, class) BOOL setFooterLogoClickable;)
+ (BOOL)setFooterLogoClickable SWIFT_WARN_UNUSED_RESULT;
+ (void)setSetFooterLogoClickable:(BOOL)newValue;
+ (void)sendEventWithEvent:(NSString * _Nonnull)event;
+ (void)sendEvent:(NSString * _Nonnull)eventName;
/// Initialize the <em>Usabilla SDK</em>
/// This method should be called once, inside the AppDelegate <em>didFinishLaunchingWithOptions</em> method.
/// The initialization allows to send previous persisted feedbacks if it was not possible to send them because of an internet connection issue for example.
/// It also allows to fetch the campaigns associated to the <em>appID</em>.
/// \param appID The app identifier (eg: <em>0D5424BE-41AD-4434-A081-32C393A998A3</em>)
///
+ (void)initializeWithAppID:(NSString * _Nullable)appID completion:(void (^ _Nullable)(void))completion;
/// If it’s needed to dismiss a campaign this method will dismiss the current presented campaign.
///
/// returns:
/// true if there is a campaign and it’s closed, false if there is no presented campaign
+ (BOOL)dismiss SWIFT_WARN_UNUSED_RESULT;
+ (void)removeCachedForms;
+ (void)resetCampaignData;
/// Preloads a list of forms to make them available to the user even without network connectivity.
+ (void)preloadFeedbackFormsWithFormIDs:(NSArray<NSString *> * _Nonnull)formIDs;
+ (void)loadFeedbackForm:(NSString * _Nonnull)formID screenshot:(UIImage * _Nullable)screenshot;
+ (void)showFeedbackForm:(NSString * _Nonnull)formID;
+ (UIImage * _Nullable)takeScreenshot:(UIView * _Nonnull)view SWIFT_WARN_UNUSED_RESULT;
+ (void)setDataMaskingWithMasks:(NSArray<NSString *> * _Nonnull)masks maskCharacter:(NSString * _Nonnull)maskCharacter;
+ (void)setThemWithJson:(NSString * _Nonnull)jsonString;
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end


@class UINavigationController;
@class NSData;

SWIFT_PROTOCOL_NAMED("UsabillaDelegate")
@protocol UsabillaDelegate
/// This method is called once a passive feedback form is correctly loaded
/// \param form The view controller containing the form
///
- (void)formDidLoadWithForm:(UINavigationController * _Nonnull)form;
/// This method is called if the SDK encountered an error while loading the passive feedback form
/// \param error An error describing the issue encoutered
///
- (void)formDidFailLoadingWithError:(id _Nonnull)error;
/// This method is called once the form is closed
/// withFeedbackResults can contain between 1 and n FeedbackResult
/// \param formID String representing the ID of the form
///
/// \param withFeedbackResults Array of FeedbackResult
///
/// \param isRedirectToAppStoreEnabled Indicates whether or not the form is set to redirect to the App Store
///
- (void)formDidCloseWithFormID:(NSString * _Nonnull)formID withFeedbackResults:(NSArray<FeedbackResult *> * _Nonnull)results isRedirectToAppStoreEnabled:(BOOL)isRedirectToAppStoreEnabled;
/// This method is called before the form is closed
/// This method should be used to dismiss the form if the Usabilla.<em>dismissAutomatically</em> attribute is set to <em>false</em>
/// \param form UINavigationcontroller which is being dismissed
///
/// \param formID String representing the ID of the form
///
/// \param withFeedbackResults Array of FeedbackResult
///
/// \param isRedirectToAppStoreEnabled Indicates whether or not the form is set to redirect to the App Store
///
- (void)formWillCloseWithForm:(UINavigationController * _Nonnull)form formID:(NSString * _Nonnull)formID withFeedbackResults:(NSArray<FeedbackResult *> * _Nonnull)results isRedirectToAppStoreEnabled:(BOOL)isRedirectToAppStoreEnabled;
/// This method is called once a campaign form is closed
/// \param withFeedbackResult FeedbackResult containing the campaign data submitted by the user
///
/// \param isRedirectToAppStoreEnabled Bool indicating whether or not the form is set to redirect to the App Store
///
- (void)campaignDidCloseWithFeedbackResult:(FeedbackResult * _Nonnull)result isRedirectToAppStoreEnabled:(BOOL)isRedirectToAppStoreEnabled;
/// This method is called once a campaign or feedback Form is being submittted
/// \param userResponse Dictionary<String, Any> containing the answers submitted by the user
///
- (void)feedbackResultSubmittedWithUserResponse:(NSData * _Nonnull)userResponse;
@end

#endif
#if defined(__cplusplus)
#endif
#if __has_attribute(external_source_symbol)
# pragma clang attribute pop
#endif
#pragma clang diagnostic pop
#endif

#else
#error unsupported Swift architecture
#endif
