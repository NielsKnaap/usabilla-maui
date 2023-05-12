﻿using System;
using Foundation;
using UIKit;

namespace UsabillaIos
{
    [BaseType(typeof(NSObject), Name = "FeedbackResult")]
    interface FeedbackResult
    {
        [Export("rating")]
        string Rating { get; set; }
        [Export("abandonedPageIndex")]
        string AbandonedPageIndex { get; set; }
        [Export("sent")]
        bool Sent { get; }
    }

    [BaseType(typeof(NSObject), Name = "UBError")]
    interface UBError
    {
        [Export("errorDescription")]
        string description { get; set; }
    }

    [BaseType(typeof(NSObject), Name = "Usabilla")]
    interface Usabilla
    {
        [Static, Export("initializeWithAppID:completion:")]
        void Initialize([NullAllowed] string appId, [NullAllowed] Action completion);

        [Static, Export("customVariables")]
        NSDictionary<NSString, NSString> CustomVariables { get; set; }

        [Static, Export("delegate"), NullAllowed]
        UsabillaDelegate Delegate { get; set; }

        [Static, Export("localizedStringFile")]
        string LocalizedStringFile { get; set; }

        [Static, Export("dismissAutomatically")]
        bool DismissAutomatically { get; set; }

        [Static, Export("canDisplayCampaigns")]
        bool CanDisplayCampaigns { get; set; }

        [Static, Export("debugEnabled")]
        bool DebugEnabled { get; set; }

        [Static, Export("sendEvent:")]
        void SendEvent(string eventName);

        [Static, Export("removeCachedForms")]
        void RemoveCachedForms();

        [Static, Export("resetCampaignData")]
        void ResetCampaignData();

        [Static, Export("preloadFeedbackForms:")]
        void PreloadFeedbackForms(String[] formIDs);

        [Static, Export("loadFeedbackForm:screenshot:")]
        void LoadFeedbackForm(string formID, [NullAllowed] UIImage image);

        [Static, Export("takeScreenshot:")]
        [NullAllowed] UIImage TakeScreenshot(UIView view);

        [Static, Export("dismiss")]
        bool Dismiss();

        [Static, Export("setDataMasking:masks:maskCharacter")]
        void SetDataMasking([NullAllowed] string[] mask, [NullAllowed] char maskCharacter);

        [Static, Export("defaultDataMasks")]
        string[] DefaultDataMasks { get; }
    }

    [BaseType(typeof(NSObject))]
    [Model]
    [Protocol]
    interface UsabillaDelegate
    {
        [Abstract]
        [Export("formDidLoadWithForm:")]
        void FormDidLoad(UINavigationController form);

        [Abstract]
        [Export("formDidFailLoadingWithError:")]
        void FormDidFailLoading(UBError description);

        [Export("formDidCloseWithFormID:withFeedbackResults:isRedirectToAppStoreEnabled:")]
        void FormDidClose(string formID, FeedbackResult[] result, bool isRedirectToAppStoreEnabled);

        [EventArgs("FormWillClose")]
        [Export("formWillCloseWithForm:formID:withFeedbackResults:isRedirectToAppStoreEnabled:")]
        void FormWillClose(UINavigationController form, String formID, FeedbackResult[] result, bool isRedirectToAppStoreEnabled);

        [Export("campaignDidCloseWithFeedbackResult:isRedirectToAppStoreEnabled:")]
        void CampaignDidClose(FeedbackResult feedbackResult, bool isRedirectToAppStoreEnabled);

        [Export("feedbackResultSubmittedWithUserResponse:")]
        void feedbackResultSubmittedWithUserResponse(NSData userResponse);
    }
}