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
    id: itp
    property alias itemPageTitle: titlebar.title
    property alias pass: password.text
    property int i: i

    titleBar: TitleBar {
        id: titlebar
        scrollBehavior: TitleBarScrollBehavior.Sticky
        title: "pass"
    }

    Container {
        topPadding: 10.0
        leftPadding: 10.0
        rightPadding: 10.0
        bottomPadding: 10.0
        TextField {
            id: password
            inputMode: TextFieldInputMode.Password
            enabled: false
            textStyle.fontFamily: "Monospace"

        }

    }
    
    actions: [
        ActionItem {
            title: qsTr ("Edit")
            imageSource: "asset:///img/ic_edit.png"
            ActionBar.placement: ActionBarPlacement.InOverflow

            onTriggered: {
                var contentpage = editPageDefinition.createObject();
                contentpage.acc = accListModel.getAccountAt(i)
                contentpage.startV = accListModel.getStartAt(i)
                contentpage.stopV = accListModel.getStopAt(i)
                contentpage.i = i
                nav.push(contentpage);
            }
        },
        ActionItem {
            title: qsTr ("Delete")
            imageSource: "asset:///img/ic_delete.png"
            ActionBar.placement: ActionBarPlacement.InOverflow

            onTriggered: {
                accListModel.removeAccountAt(i)
                accLst.reload()
                nav.pop()
            }
        },
        ActionItem {
            title: qsTr ("Copy Password")
            imageSource: "asset:///img/ic_copy_password.png"
            ActionBar.placement: ActionBarPlacement.OnBar
            
            onTriggered: {
                accListModel.copyToClipboard(password.text)
            }
        }
    ]

}
