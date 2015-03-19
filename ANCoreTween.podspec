Pod::Spec.new do |s|

  s.name          = 'ANCoreTween'
  s.version       = '0.1.0'
  s.summary       = 'A Core Tween Timing Funcation Library'
  s.homepage      = 'https://github.com/candyan/ANCoreTween.git'
  s.license       = 'MIT'
  s.author        = { 'Candyan' => 'liuyanhp@gmail.com' }
  s.platform      = :ios, '6.0'
  s.source        = {
      :git => 'https://github.com/candyan/ANCoreTween.git',
      :tag => s.version.to_s
  }

  s.source_files  = 'Source/*.{h,c}'

end
