#
# Be sure to run `pod lib lint Ads_OSET.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see https://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
    s.name             = 'Ads_OSET'
    s.version          = '0.0.1'
    s.summary          = 'A short description of Ads_OSET.'
    
    # This description is used to generate tags and improve search results.
    #   * Think: What does it do? Why did you write it? What is the focus?
    #   * Try to keep it short, snappy and to the point.
    #   * Write the description between the DESC delimiters below.
    #   * Finally, don't worry about the indent, CocoaPods strips it!
    
    s.description      = <<-DESC
    TODO: Add long description of the pod here.
    DESC
    
    s.homepage         = 'https://github.com/xierwanasi/Ads_OSET'
    s.license          = { :type => 'MIT', :file => 'LICENSE' }
    s.author           = { 'xierwanasid' => 'wangpengqqd@163.com' }
    s.source           = { :git => 'https://github.com/xierwanasi/Ads_OSET.git', :tag => s.version.to_s }
    
    s.ios.deployment_target = '13.0'
    s.static_framework = true
    
    s.subspec 'OSETSDK' do |osset|
        
        s.pod_target_xcconfig = {
            'OTHER_LDFLAGS' => '-ObjC -l"c++" -l"c++abi" -l"sqlite3" -l"z"',
            'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64',
            'VALID_ARCHS' => 'armv7 arm64',
        }
        
        s.vendored_frameworks = 'OSetSDK/Frameworks/Tanx/TanxSDK.framework', 'OSetSDK/Frameworks/Tanx/TNXASDK.framework', 'OSetSDK/Frameworks/OSETSDK.xcframework'
        
        # 配置资源包
        s.resource_bundles = {
            'Ads_OSET' => ['OSetSDK/Assets/OSETSDK.bundle/**/*']
        }
        
        s.frameworks = 'SafariServices', 'CFNetwork', 'AVFoundation', 'WebKit', 'StoreKit', 'Security', 'CoreTelephony',
        'SystemConfiguration', 'QuartzCore', 'CoreLocation', 'AdSupport', 'Accelerate', 'ImageIO', 'CoreMotion', 'CoreMedia',
        'MediaPlayer', 'MobileCoreServices', 'MessageUI', 'AudioToolbox', 'CoreGraphics', 'DeviceCheck'
        s.libraries  = 'xml2', 'z', 'sqlite3', 'c++', 'resolv.9', 'xml2.2', 'iconv', 'bz2.1.0', 'z.1.2.5', 'c++abi'
        
        s.dependency 'Ads-CN-Beta/BUAdSDK', '~> 6.2.0.1'
        s.dependency 'Ads-CN-Beta/CSJMediation', '~> 6.2.0.1'
        s.dependency 'GDTMobSDK', '~> 4.14.81'
        s.dependency 'SigmobAd-iOS', '~> 4.13.0'
        s.dependency 'BaiduMobAdSDK', '~> 5.36'
        s.dependency 'BeiZiSDK-iOS/BeiZiSDK-iOS', '~> 4.90.4.8'
        s.dependency 'OctopusSDK', '~> 1.6.0.10'
        
    end
    
    s.subspec 'KSAdSDK' do |ksad|
        
        ksad.libraries = ["z", "resolv.9", "sqlite3", "c++", "c++abi"]
        
        ksad.ios.vendored_framework  = 'KSAdSDK/Frameworks/KSAdSDK.xcframework'
        
        ksad.frameworks = ["Foundation", "UIKit", "MobileCoreServices", "CoreGraphics", "Security", "SystemConfiguration",
        "CoreTelephony", "AdSupport", "CoreData", "StoreKit", "AVFoundation", "MediaPlayer", "CoreMedia",
        "WebKit", "Accelerate", "CoreLocation", "AVKit", "MessageUI", "QuickLook", "AudioToolBox",
        "JavaScriptCore", "CoreMotion"]
    end
    
end
