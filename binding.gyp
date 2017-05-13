{
  "targets": [
    {
      "target_name": "osxreachability",
      "include_dirs": ["<!(node -e \"require('nan')\")"],
      "sources": [ "reach.cc", "Reachability.mm" ],
      "cflags": ["-Wall", "-std=c++11","-framework IOKit","-framework CoreFoundation","-framework CoreAudio"],
      "conditions": [ 
        [ "OS=='mac'", { 
            "xcode_settings": { 
                "OTHER_CPLUSPLUSFLAGS" : ["-std=c++11","-stdlib=libc++"], 
                "OTHER_LDFLAGS": ["-stdlib=libc++"], 
                "MACOSX_DEPLOYMENT_TARGET": "10.7" } 
            }
        ] 
      ] 
    }
  ]
}
