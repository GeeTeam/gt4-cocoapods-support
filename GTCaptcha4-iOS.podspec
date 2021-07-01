#
#  Be sure to run `pod spec lint GTCaptcha4-iOS.podspec' to ensure this is a
#  valid spec and to remove all comments including this before submitting the spec.
#
#  To learn more about Podspec attributes see https://guides.cocoapods.org/syntax/podspec.html
#  To see working Podspecs in the CocoaPods repo see https://github.com/CocoaPods/Specs/
#

Pod::Spec.new do |spec|

  spec.name         = "GTCaptcha4-iOS"
  spec.version      = "1.5.0"
  spec.summary      = "极验适应性验证SDK。"
  spec.homepage     = "https://www.geetest.com"
  spec.license      = {:type => "MIT", :file => "LICENSE"}
  spec.author       = {"Geetest" => "xuwei@geetest.com"}
  spec.ios.deployment_target = "8.0"

  spec.source       = { :git => "https://github.com/GeeTeam/gt4-cocoapods-support.git", :tag => spec.version }

  spec.frameworks   = 'WebKit'

  spec.vendored_frameworks = "SDK/GTCaptcha4.framework"
  spec.resources = "SDK/GTCaptcha4.bundle"

  spec.pod_target_xcconfig      = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64' }
  spec.user_target_xcconfig     = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64' }

end
