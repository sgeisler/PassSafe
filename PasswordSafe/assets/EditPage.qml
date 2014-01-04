/*
 * Copyright (c) 2011-2013 BlackBerry Limited.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

import bb.cascades 1.0

Page {
    property alias acc: account.text
    property alias startV: start.value
    property alias stopV: stop.value
    property int i: i

    titleBar: TitleBar {
        id: titlebar
        scrollBehavior: TitleBarScrollBehavior.Sticky
        title: "Edit Account"
        acceptAction: ActionItem {
            title: "save"
            onTriggered: {
                accListModel.editAccount(i, account.text, start.value, stop.value)
                nav.pop()
                nav.pop()
            }

        }
    }

    Container {
        TextField {
            id: account
            inputMode: TextFieldInputMode.EmailAddress
            textStyle.fontFamily: "Monospace"
            text: ""
            hintText: "account"

        }

        
        Container {
            layout: StackLayout {
                orientation: LayoutOrientation.LeftToRight

            }

            topMargin: 40.0
            Label {
                text: "start:"

            }
            Slider {
                id: start
                fromValue: 1.0
                toValue: 28.0
                value: 1.0
                
                maxWidth: 500.0
                preferredWidth: 500.0
                minWidth: 500.0
                
                onValueChanged: {
                    start.value = Math.round(start.value)
                    startVal.text = Math.round(start.value).toString()
                    stop.fromValue = Math.round(start.value).toString()
                }
                onImmediateValueChanged: {
                    startVal.text = Math.round(immediateValue).toString()
                    preview.text = accListModel.getPasswordAt(i, Math.round(immediateValue), stop.value)
                }

            }
            Label {
                id: startVal
                text: "1"

            }
        }
        
        Container {
            layout: StackLayout {
                orientation: LayoutOrientation.LeftToRight
            
            }

            topMargin: 40.0
            Label {
                text: "stop:"
            
            }
            Slider {
                id: stop
                fromValue: 1.0
                toValue: 28.0
                
                
                maxWidth: 500.0
                preferredWidth: 500.0
                minWidth: 500.0
                onValueChanged: {
                    stop.value = Math.round(stop.value)
                    stopVal.text = Math.round(stop.value).toString()
                }
                onImmediateValueChanged: {
                    stopVal.text = Math.round(immediateValue).toString()
                    preview.text = accListModel.getPasswordAt(i, start.value, Math.round(immediateValue))

                }

            }
            Label {
                id: stopVal
                text: "1"
            
            }
             
        }
        TextField {
            id: preview
            topMargin: 60.0
            inputMode: TextFieldInputMode.Password

        }
        Label {
            multiline: true
            text: "Note: the '=' at the end is NOT random. Only use it if you need a special character. The password will not get more secure by adding it!"

        }

    }

}
