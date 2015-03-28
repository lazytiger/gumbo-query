#  Build the doxygen documentation for the project and load the docset into Xcode.

#  Use the following to adjust the value of the $DOXYGEN_PATH User-Defined Setting:
#    Binary install location: /Applications/Doxygen.app/Contents/Resources/doxygen
#    Source build install location: /usr/local/bin/doxygen

#  If the config file doesn't exist, run 'doxygen -g $SOURCE_ROOT/Doxyfile.config' to
#   a get default file.

DOXYGEN_PATH="/Applications/Doxygen.app/Contents/Resources/doxygen"
DOXYFILE_PATH=$SOURCE_ROOT"/../Doxyfile.config"
DOCSET_PATH=$SOURCE_ROOT"/../"$PRODUCT_NAME".docset"
DOCSET_BUNDLE_ID="com.google."$PRODUCT_NAME

if ! [ -f $DOXYFILE_PATH ]
then
    echo "Doxyfile config does not exist"
    $DOXYGEN_PATH -g $DOXYFILE_PATH
fi

#  Append the proper input/output directories and docset info to the config file.
#  This works even though values are assigned higher up in the file. Easier than sed.

cp $DOXYFILE_PATH $TEMP_DIR/Doxyfile.config

echo "INPUT = $SOURCE_ROOT" >> $TEMP_DIR/Doxyfile.config
echo "OUTPUT_DIRECTORY = $DOCSET_PATH" >> $TEMP_DIR/Doxyfile.config
echo "GENERATE_DOCSET        = YES" >> $TEMP_DIR/Doxyfile.config
echo "DOCSET_BUNDLE_ID       = $DOCSET_BUNDLE_ID" >> $TEMP_DIR/Doxyfile.config

#  Run doxygen on the updated config file.
#  Note: doxygen creates a Makefile that does most of the heavy lifting.

$DOXYGEN_PATH $TEMP_DIR/Doxyfile.config

#  make will invoke docsetutil. Take a look at the Makefile to see how this is done.

make -C $DOCSET_PATH/html install

#  Construct a temporary applescript file to tell Xcode to load a docset.

rm -f $TEMP_DIR/loadDocSet.scpt

echo -e "tell application \"Xcode\"\n\tload documentation set with path \"/Users/$USER/Library/Developer/Shared/Documentation/DocSets/"$DOCSET_BUNDLE_ID".docset\"\nend tell" >> $TEMP_DIR/loadDocSet.scpt

#  Run the load-docset applescript command.

osascript $TEMP_DIR/loadDocSet.scpt

exit 0