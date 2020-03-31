#!/usr/bin/env bash
### Configuration
# Djinni IDL file location
djinni_file="nok.djinni"
# C++ namespace for generated src
namespace="nok"
# Objective-C class name prefix for generated src
objc_prefix="NOK"
# Java package name for generated src
java_package="co.zenturi.$namespace"


### Script
# get base directory
base_dir=$(cd "`dirname "0"`" && pwd)
# get java directory from package name
java_dir=$(echo $java_package | tr . /)
# output directories for generated src
cpp_out="$base_dir/../src/djinni/cpp/$namespace"
objc_out="$base_dir/../src/djinni/objc/$namespace"
jni_out="$base_dir/../src/djinni/jni/$namespace"
java_out="$base_dir/../src/djinni/java/$java_dir"
# clean generated src dirs
rm -rf $cpp_out
rm -rf $jni_out
rm -rf $objc_out
rm -rf $java_out 
# execute the djinni command
../djinni-react/src/run \
   --cpp-out $cpp_out \
   --cpp-namespace $namespace \
   --java-out $java_out \
   --java-package $java_package \
   --ident-java-field mFooBar \
   --jni-out $jni_out \
   --ident-jni-class NativeFooBar \
   --ident-jni-file NativeFooBar \
   --objc-out $objc_out \
   --objc-type-prefix $objc_prefix \
   --objcpp-out $objc_out \
   --idl $djinni_file