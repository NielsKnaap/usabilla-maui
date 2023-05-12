# Usabilla .NET MAUI Binding Library

The Usabilla .NET MAUI Binding Library is a library that allows you to access the native SDKs of Usabilla in a .NET MAUI application. This library is based on the Xamarin.forms binding library repository of Usabilla itself.

** Note **
- This repository is not yet a finished product. Missing the nuget package and PCL piece, which means that the platform-specific implementation must be added per project (see usage).
- The binding library is fully functional as far as we have tested.
- In this readme we have not documented how the binding library works, but only what extra steps are needed compared to the Xamarin.Forms binding library. For documentation on the binding library, we refer you to [the original Xamarin.Forms repository](https://github.com/usabilla/usabilla-u4a-xamarin).
## Contents

- [Installation](#installation)
- [Usage](#usage)
- [Contributing](#contributing)
- [License](#license)

## Installation

We have been attempting to create a NuGet package for our project, but unfortunately, we have not been successful in doing so yet. The current NuGet specification does produce a functioning Android version, but the iOS version is not yet working properly.

As a result, the only way to use our repository at the moment is to clone it into your solution. To do so, you need to follow these steps:

1. Open your solution in Visual Studio (On time of writing Rider can't really handle MAUI binding libraries)
2. Go to the "Solution Explorer" panel on the right-hand side of the screen.
3. Right-click on the solution, and select "Add" -> "Existing Project".
4. Navigate to the location where you cloned our repository, and select the appropriate project file (either the iOS or Android version).
5. Click "OK" to add the project to your solution.

- Now we need to add a reference to the projects inside the MAUI project where we want to use it:
6. Right click on the project -> Edit project file
7. We want to add the platform specific project only when building for that framework, this is done by adding the following between the `<Project>` tag:
```
<ItemGroup Condition="'$(TargetFramework)' == 'net7.0-android'">
    <ProjectReference Include="..\Usabilla\Android\UsabillaAndroidSdk.csproj" />
</ItemGroup>

<ItemGroup Condition="'$(TargetFramework)' == 'net7.0-ios'">
    <Reference Include="TestUsabillaBindingIos">
    <HintPath>..\Usabilla\Ios\bin\Debug\net7.0-ios\UsabillaBindingIos.dll</HintPath>
    </Reference>
</ItemGroup>
```
* The HintPaths should be changed to the location where you cloned our repository
The iOS reference is directly targeting the assembly of the project (only available after a succesfull build). This is because on the time of writing the project reference of a iOS binding project isn't working in Visual Studio.


Once you have added the project to your solution, you should be able to use it as normal.

## Usage
Usabilla's original Xamarin.Forms library includes a built-in PCL project that already contains platform-specific implementations. However, this feature is not yet available in the current version of this .NET MAUI binding library and needs to be added manually. This consits of the following:
- IUsabillaMaui.cs

```csharp
namespace SampleUsabillaMaui
{
    public interface IXUFormCompletionResult
    {
        bool isFormSucceeded { get; }
        string? formId { get; }
        IUBFeedback? result { get; }
        bool? isRedirectToAppStoreEnabled { get; }
        IUBError? error { get; }
    }
    public interface IUBError
    {
        string description { get; }
    }
    public interface IUBFeedback
    {
        int Rating { get; }
        int AbandonedPageIndex { get; }
        bool Sent { get; }
    }
    public interface IUsabillaMaui
    {
        bool DebugEnabled { get; set; }

        IDictionary<string, string> CustomVariables { get; set; }

        IList<string> DefaultMasks { get; }

        void Initialize(string appId, Action<IXUFormCompletionResult> result);

        void SendEvent(string anEvent, Action<IXUFormCompletionResult> result);

        void Reset();

        void ShowFeedbackForm(string formId, Action<IXUFormCompletionResult> result);

        void ShowFeedbackFormWithScreenshot(string formId, Action<IXUFormCompletionResult> result);

        bool Dismiss();

        void SetDataMasking(IList<string> masks, char maskCharacter);

        void PreloadFeedbackForms(IList<string> formIds);

        void RemoveCachedForms();

        string LocalizedStringFile { get; set; }

    }
}
```
- UsabillaMaui.cs (inside the Android platform folder)
```csharp
namespace SampleUsabillaMaui.Platforms
{
    public sealed class UBError : object
    {
        private string _description;
        public UBError(string desc)
        {
            _description = desc;
        }

        public string description
        {
            get
            {
                return _description;
            }
        }
    }

    public sealed class UBFeedbackResult : IXUFormCompletionResult
    {
        private bool _isFormSucceeded;
        private UBFeedback? _result;
        private UBFeedbackError? _error;

        public string? formId => throw new NotImplementedException();

        public bool? isRedirectToAppStoreEnabled => throw new NotImplementedException();

        public UBFeedbackResult(UBError err)
        {
            _isFormSucceeded = false;
            _error = new UBFeedbackError(err);
        }
        public UBFeedbackResult(FeedbackResult res)
        {
            _isFormSucceeded = true;
            _result = new UBFeedback(res);
        }

        public bool isFormSucceeded
        {
            get
            {
                return _isFormSucceeded;
            }

        }

        public IUBFeedback? result
        {
            get
            {
                return _result;
            }
        }

        public IUBError? error
        {
            get
            {
                return _error;
            }
        }
    }

    public class UBFeedback : IUBFeedback
    {
        private FeedbackResult result;

        public UBFeedback(FeedbackResult res)
        {
            result = res;
        }

        public bool Sent
        {
            get
            {
                return result.IsSent;
            }
        }
        public int Rating
        {
            get
            {
                return result.Rating;
            }
        }
        public int AbandonedPageIndex
        {
            get
            {
                return result.AbandonedPageIndex;
            }
        }
    }

    public class UBFeedbackError : IUBError
    {
        private UBError error;

        public UBFeedbackError(UBError err)
        {
            error = err;
        }

        public string description
        {
            get
            {
                return error.description;
            }
        }
    }

    public class UsabillaMaui : IUsabillaMaui
    {
        public static UsabillaMaui Instance { get; } = new UsabillaMaui();

        public AndroidX.AppCompat.App.AppCompatActivity Activity { get; set; }

        public bool DebugEnabled
        {
            get => UsabillaAndroid.Usabilla.Instance.DebugEnabled;
            set => UsabillaAndroid.Usabilla.Instance.DebugEnabled = value;
        }

        public IDictionary<string, string> CustomVariables
        {
            get
            {
                Dictionary<string, string> dictionary = new Dictionary<string, string>();
                foreach (KeyValuePair<string, Java.Lang.Object> entry in UsabillaAndroid.Usabilla.Instance.CustomVariables)
                {
                    dictionary.Add(entry.Key, entry.Value.ToString());
                }
                return dictionary;
            }
            set
            {
                Dictionary<string, Java.Lang.Object> dictionary = new Dictionary<string, Java.Lang.Object>();
                foreach (KeyValuePair<string, string> entry in value)
                {
                    dictionary.Add(entry.Key, entry.Value);
                }
                UsabillaAndroid.Usabilla.Instance.CustomVariables = dictionary;
            }
        }

        public IList<string> DefaultMasks => UsabillaAndroid.UbConstants.DefaultDataMasks;

        internal Action<IXUFormCompletionResult> FormCallback { get; set; }
        public string LocalizedStringFile { get => throw new NotImplementedException(); set => throw new NotImplementedException(); }

        private readonly IntentFilter campaignFilter = new IntentFilter(UsabillaAndroid.UbConstants.IntentCloseCampaign);
        private CampaignCloseReceiver campaignReceiver;

        private class CampaignCloseReceiver : BroadcastReceiver
        {

            public CampaignCloseReceiver() { }

            public override void OnReceive(Context context, Intent intent)
            {
                if (intent != null)
                {
                    FeedbackResult parcelable = (FeedbackResult)intent.GetParcelableExtra(FeedbackResult.IntentFeedbackResultCampaign);
                    var aResponse = new UBFeedbackResult(parcelable);
                    if (Instance.FormCallback != null)
                    {
                        Instance.FormCallback(aResponse);
                    }
                }
            }
        }

        static UsabillaMaui() { }
        private UsabillaMaui() { }

        public void Initialize(string appId, Action<IXUFormCompletionResult> result = null)
        {
            UsabillaAndroid.Usabilla.Instance.Initialize(Application.Context, appId);
            //UsabillaAndroid.Usabilla.Instance.UpdateFragmentManager(Activity.SupportFragmentManager);
            FormCallback = result;

            campaignReceiver = new CampaignCloseReceiver();
            AndroidX.LocalBroadcastManager.Content.LocalBroadcastManager.GetInstance(Application.Context).RegisterReceiver(campaignReceiver, campaignFilter);
        }

        public void SendEvent(string anEvent, Action<IXUFormCompletionResult> result)
        {
            UsabillaAndroid.Usabilla.Instance.SendEvent(Application.Context, anEvent);
            FormCallback = result;
        }

        public void Reset()
        {
            UsabillaAndroid.Usabilla.Instance.ResetCampaignData(Application.Context);
        }

        public void ShowFeedbackForm(string formId, Action<IXUFormCompletionResult> result)
        {
            PassiveFeedbackActivity.start(Application.Context, formId, false);
            FormCallback = result;
        }

        public void ShowFeedbackFormWithScreenshot(string formId, Action<IXUFormCompletionResult> result)
        {
            PassiveFeedbackActivity.start(Application.Context, formId, true);
            FormCallback = result;
        }

        public bool Dismiss()
        {
            return UsabillaAndroid.Usabilla.Instance.Dismiss(Application.Context);
        }

        public void SetDataMasking(IList<string> masks = null, char maskCharacter = 'X')
        {
            masks = masks ?? UsabillaAndroid.UbConstants.DefaultDataMasks;
            UsabillaAndroid.Usabilla.Instance.SetDataMasking(masks, maskCharacter);
        }

        public void PreloadFeedbackForms(IList<string> formIds)
        {
            UsabillaAndroid.Usabilla.Instance.PreloadFeedbackForms(formIds);
        }

        public void RemoveCachedForms()
        {
            UsabillaAndroid.Usabilla.Instance.RemoveCachedForms();
        }
    }
}
```
- UsabillaMaui.cs (inside the iOS platform folder)
```csharp
namespace SampleUsabillaMaui.Platforms
{
    public sealed class UBFeedbackResult : IXUFormCompletionResult
    {
        private string? _formId;
        private UBFeedback? _result;
        private UBFeedbackError? _error;
        private bool? _isRedirectToStoreEnabled;
        private bool? _isFormSucceeded;


        public UBFeedbackResult(UBError err)
        {
            _isFormSucceeded = (_isRedirectToStoreEnabled == null) ? false : true;
            _error = new UBFeedbackError(err);
        }
        public UBFeedbackResult(FeedbackResult res, bool isRedirectEnabled)
        {
            _isFormSucceeded = (_isRedirectToStoreEnabled == null) ? false : true;
            _result = new UBFeedback(res);
            _isRedirectToStoreEnabled = isRedirectEnabled;
        }

        public UBFeedbackResult(string formID, FeedbackResult res, bool isRedirectEnabled)
        {
            _isFormSucceeded = (_isRedirectToStoreEnabled == null) ? false : true;
            _formId = formID;
            _result = new UBFeedback(res);
            _isRedirectToStoreEnabled = isRedirectEnabled;
        }

        public bool isFormSucceeded
        {
            get
            {
                return (_isFormSucceeded == null) ? false : true;
            }

        }
        public string? formId
        {
            get
            {
                return _formId;
            }
        }

        public IUBFeedback? result
        {
            get
            {
                return _result;
            }
        }

        public bool? isRedirectToAppStoreEnabled
        {
            get
            {
                return _isRedirectToStoreEnabled;
            }

        }

        public IUBError? error
        {
            get
            {
                return _error;
            }
        }
    }

    public class UBFeedbackError : IUBError
    {
        private UBError error;

        public UBFeedbackError(UBError err)
        {
            error = err;
        }

        public string description
        {
            get
            {
                return error.description;
            }
        }
    }

    public class UBFeedback : IUBFeedback
    {
        private FeedbackResult result;

        public UBFeedback(FeedbackResult res)
        {
            result = res;
        }

        public bool Sent
        {
            get
            {
                return result.Sent;
            }
        }
        public int Rating
        {
            get
            {
                return int.Parse(result.Rating);
            }
        }
        public int AbandonedPageIndex
        {
            get
            {
                return int.Parse(result.AbandonedPageIndex);
            }
        }
    }

    public sealed class UsabillaMaui : IUsabillaMaui
    {

        public static UsabillaMaui Instance { get; } = new UsabillaMaui();
        private CustomUsabillaDelegate aDelegate = new CustomUsabillaDelegate();

        static UsabillaMaui() { }
        private UsabillaMaui() { }

        public void Initialize(string appId, Action<IXUFormCompletionResult> result = null)
        {
            UsabillaIos.Usabilla.Initialize(appId, null);
            UsabillaIos.Usabilla.Delegate = aDelegate;
            if (result != null)
            {
                aDelegate.Result = result;
            }

        }

        public void SendEvent(string anEvent, Action<IXUFormCompletionResult> result)
        {
            aDelegate.Result = result;
            UsabillaIos.Usabilla.SendEvent(anEvent);
        }

        public void Reset()
        {
            UsabillaIos.Usabilla.ResetCampaignData();
        }

        public void ShowFeedbackForm(string formId, Action<IXUFormCompletionResult> result)
        {
            aDelegate.Result = result;
            UsabillaIos.Usabilla.LoadFeedbackForm(formId, null);
        }

        public void ShowFeedbackFormWithScreenshot(string formId, Action<IXUFormCompletionResult> result)
        {
            aDelegate.Result = result;
            var window = UIApplication.SharedApplication.KeyWindow;
            var vc = window.RootViewController.View;
            UIImage image = UsabillaIos.Usabilla.TakeScreenshot(vc);
            UsabillaIos.Usabilla.LoadFeedbackForm(formId, image);
        }

        public IDictionary<string, string> CustomVariables
        {
            get
            {
                Dictionary<string, string> dictionary = new Dictionary<string, string>();
                foreach (KeyValuePair<NSObject, NSObject> entry in UsabillaIos.Usabilla.CustomVariables)
                {
                    dictionary.Add(entry.Key.ToString(), entry.Value.ToString());
                }
                return dictionary;
            }

            set
            {
                NSMutableDictionary<NSString, NSString> dictionary = new NSMutableDictionary<NSString, NSString>();
                foreach (KeyValuePair<string, string> entry in value)
                {
                    dictionary.Add((NSString)entry.Key, (NSString)entry.Value);
                }

                NSDictionary<NSString, NSString> aDictionary = new NSDictionary<NSString, NSString>(dictionary.Keys, dictionary.Values);
                if (aDictionary != null)
                {
                    UsabillaIos.Usabilla.CustomVariables = aDictionary;
                }
            }
        }

        public bool Dismiss()
        {
            return UsabillaIos.Usabilla.Dismiss();
        }

        public void SetDataMasking(IList<string> masks = null, char maskCharacter = 'X')
        {
            string[] stringArray = null;
            if (masks != null)
            {
                stringArray = new string[masks.Count];
                masks.CopyTo(stringArray, 0);
            }
            UsabillaIos.Usabilla.SetDataMasking(stringArray, maskCharacter);
        }

        public IList<string> DefaultMasks
        {
            get
            {
                string[] masks = UsabillaIos.Usabilla.DefaultDataMasks;
                List<string> list = new List<string>(masks);
                return list;
            }
        }

        public bool DebugEnabled
        {
            get
            {
                return UsabillaIos.Usabilla.DebugEnabled;
            }

            set
            {
                UsabillaIos.Usabilla.DebugEnabled = value;
            }
        }

        public string LocalizedStringFile
        {
            get
            {
                return UsabillaIos.Usabilla.LocalizedStringFile;
            }

            set
            {
                UsabillaIos.Usabilla.LocalizedStringFile = value;
            }
        }

        public void PreloadFeedbackForms(IList<string> formIds)
        {
            string[] formIdArray = null;
            if (formIds != null)
            {
                formIdArray = new string[formIds.Count];
                formIds.CopyTo(formIdArray, 0);
                UsabillaIos.Usabilla.PreloadFeedbackForms(formIdArray);
            }
        }

        public void RemoveCachedForms()
        {
            UsabillaIos.Usabilla.RemoveCachedForms();
        }

        /*
         * Private delegate implementation
         */
        private class CustomUsabillaDelegate : UsabillaIos.UsabillaDelegate
        {
            private Action<IXUFormCompletionResult> result;
            private UINavigationController currentForm;
            public Action<IXUFormCompletionResult> Result { get => result; set => result = value; }

            public override void CampaignDidClose(FeedbackResult withFeedbackResult, bool isRedirectToAppStoreEnabled)
            {
                var obj = withFeedbackResult;
                var aResponse = new UBFeedbackResult(obj, isRedirectToAppStoreEnabled);
                if (result != null)
                {
                    result.Invoke(aResponse);
                }
            }

            public override void FormDidClose(string formID, FeedbackResult[] withFeedbackResults, bool isRedirectToAppStoreEnabled)
            {
                var obj = withFeedbackResults[0];
                var aResponse = new UBFeedbackResult(formID, obj, isRedirectToAppStoreEnabled);
                result.Invoke(aResponse);
            }

            public override void FormDidFailLoading(UBError error)
            {
                var aResponse = new UBFeedbackResult(error);
                result.Invoke(aResponse);
            }

            public override void FormDidLoad(UINavigationController form)
            {
                currentForm = form;
                presentForm();
            }

            public override void FormWillClose(UINavigationController form, string formID, FeedbackResult[] withFeedbackResult, bool isRedirectToAppStoreEnabled)
            {
                //throw new NotImplementedException();
            }

            private void presentForm()
            {
                if (currentForm != null)
                {
                    var window = UIApplication.SharedApplication.KeyWindow;
                    var vc = window.RootViewController;
                    currentForm.ModalPresentationStyle = UIModalPresentationStyle.FullScreen;
                    vc.PresentViewController(currentForm, true, null);
                    return;
                }
            }

            public override void feedbackResultSubmittedWithUserResponse(NSData data)
            {

            }
        }
    }
}
```

## Contributing

If you want to contribute to the Usabilla .NET MAUI Binding Library, you can fork the repository and then submit a pull request with your changes.

We recommend that you first create an issue to discuss your idea or problem before you start making changes.

## License

The Usabilla .NET MAUI Binding Library is available under the MIT license. See the [LICENSE](LICENSE) file for more information.